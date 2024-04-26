#include "VecmathVisualizer.h"
#include <array>
#include <chrono>
#include <stdexcept>

#include "Core/RenderSystem2D.h"
#include "Core/SimpleRenderSystem.h"
#include "Core/VMVBuffer.h"
#include "Core/VMVFrameInfo.h"
#include "Core/VMVModel.h"
#include "KeyboardMovementController.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include "glm/ext.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/vector_angle.hpp>

#include <Scalar.h>
#include <Vector3D.h>
#include <iostream>

vmv::VecmathVisualizer::VecmathVisualizer()
{
    Load();
}

vmv::VecmathVisualizer::~VecmathVisualizer() {}

void vmv::VecmathVisualizer::Run()
{
    RenderSystem2D renderSystem2D{m_VMVDevice, m_VMVRenderer.GetSwapChainRenderPass()};
    SimpleRenderSystem renderSystem{m_VMVDevice, m_VMVRenderer.GetSwapChainRenderPass()};

    VMVGameObject viewer{VMVGameObject::CreateGameObject()};
    VMVCamera camera{};

    KeyboardMovementController input{};

    using namespace std::chrono;
    time_point currentTime{high_resolution_clock::now()};

    while (!m_VMVWindow.ShouldClose())
    {
        glfwPollEvents();
        time_point newTime{high_resolution_clock::now()};
        float frameTime{duration<float, seconds::period>(newTime - currentTime).count()};
        currentTime = newTime;

        input.MoveInPlaneXZ(m_VMVWindow.GetWindow(), frameTime, viewer);
        camera.SetViewEuler(viewer.m_Transform.translation, viewer.m_Transform.yaw, viewer.m_Transform.pitch);

        float aspect{m_VMVRenderer.GetAspectRatio()};
        // camera.SetOrthographicProjection(-aspect, aspect, -1, 1, -1, 1);
        camera.SetPerspectiveProjection(glm::radians(50.f), aspect, .1f, 1000.f);

        while (!m_ToAddNextFrame.empty())
        {
            GameObjectAddRequest& request = m_ToAddNextFrame.front();

            request.gameObject.m_Model = VMVModel::CreateModelFromFile(m_VMVDevice, request.modelPath, request.color);
            m_GameObjects.push_back(std::move(request.gameObject));

            m_ToAddNextFrame.pop();
        }

        if (VkCommandBuffer commandBuffer{m_VMVRenderer.BeginFrame()})
        {
            int frameIndex{m_VMVRenderer.GetFrameIndex()};
            VMVFrameInfo frameInfo{frameIndex, frameTime, commandBuffer, camera};

            // render
            m_VMVRenderer.BeginSwapChainRenderPass(commandBuffer);
            renderSystem2D.DrawGameObjects(frameInfo, m_GameObjects2D);
            renderSystem.DrawGameObjects(frameInfo, m_GameObjects);
            m_VMVRenderer.EndSwapChainRenderPass(commandBuffer);

            m_VMVRenderer.EndFrame();
        }
    }

    vkDeviceWaitIdle(m_VMVDevice.device());
}

void vmv::VecmathVisualizer::AddVariableDisplay(const std::string& id, IMatrix* pMatrix, float r, float g, float b)
{
    glm::vec4 color{r, g, b, 1};

    Scalar* asScalar{dynamic_cast<Scalar*>(pMatrix)};
    if (asScalar != nullptr)
    {
    }

    Vector3D* asVector3D{dynamic_cast<Vector3D*>(pMatrix)};
    if (asVector3D != nullptr)
    {
        VMVGameObject gameObject{VMVGameObject::CreateGameObject()};
        glm::vec3 pos{asVector3D->get(0, 0), asVector3D->get(0, 1), asVector3D->get(0, 2)};

        float r{std::sqrtf(pos.x * pos.x + pos.y * pos.y + pos.z * pos.z)};

        float yAngle{std::acosf(pos.y / r)};
        float xAngle{std::atan2f(pos.z, pos.x)};

        gameObject.m_Transform.pitch = 3.1415f - yAngle;
        gameObject.m_Transform.yaw = xAngle;

        gameObject.m_Transform.scale = {0.75f, r, 0.75f};

        m_ToAddNextFrame.push(GameObjectAddRequest{"data/models/arrow_body.obj", color, std::move(gameObject)});
    }
}

void vmv::VecmathVisualizer::ClearVariableDisplays()
{
    if (m_GameObjects.size() <= 1)
        return;

    for (size_t i{1}; i < m_GameObjects.size(); ++i)
    {
        m_GameObjects[i].m_Show = false;
    }
}

// GameObjects/Models loaded on construction
void vmv::VecmathVisualizer::Load()
{
    std::shared_ptr<VMVModel> coordSystemModel{VMVModel::CreateModelFromFile(
        m_VMVDevice, "data/models/coordinate_system.obj", glm::vec4{0.8f, 0.8f, 0.8f, 1.f})};

    VMVGameObject coordSystem{VMVGameObject::CreateGameObject()};
    coordSystem.m_Model = coordSystemModel;
    coordSystem.m_Transform.translation = {0.f, 0.f, 0.f};
    coordSystem.m_Transform.scale = {1.f, -1.f, 1.f};

    m_GameObjects.push_back(std::move(coordSystem));
}
