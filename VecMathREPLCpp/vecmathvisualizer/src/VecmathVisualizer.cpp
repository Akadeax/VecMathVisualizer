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
        camera.SetViewEuler(viewer.m_Transform.translation, viewer.m_Transform.rotation);

        float aspect{m_VMVRenderer.GetAspectRatio()};
        // camera.SetOrthographicProjection(-aspect, aspect, -1, 1, -1, 1);
        camera.SetPerspectiveProjection(glm::radians(50.f), aspect, .1f, 1000.f);

        while (!m_ToAddNextFrame.empty())
        {
            m_GameObjects.emplace_back(std::move(m_ToAddNextFrame.front()));
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

glm::vec3 orthogonal(glm::vec3 v)
{
    float x = std::abs(v.x);
    float y = std::abs(v.y);
    float z = std::abs(v.z);

    glm::vec3 other =
        x < y ? (x < z ? glm::vec3(1, 0, 0) : glm::vec3(0, 0, 1)) : (y < z ? glm::vec3(0, 1, 0) : glm::vec3(0, 0, 1));
    return glm::cross(v, other);
}

glm::quat getRotationBetween(glm::vec3 u, glm::vec3 v)
{
    u = glm::normalize(u);
    v = glm::normalize(v);

    if (u == -v)
    {
        return glm::quat{0, glm::normalize(orthogonal(u))};
    }

    glm::vec3 half = glm::normalize(u + v);
    glm::vec3 cross = glm::cross(u, half);
    return glm::quat{glm::dot(u, half), cross.x, cross.y, cross.z};
}

glm::vec3 yawPitchToEulerAngles(double yaw, double pitch)
{
    // Assuming ZYX rotation order (yaw-pitch-roll)
    // Convert angles from degrees to radians
    const float PI = 3.1415f;
    yaw = yaw * PI / 180.0f;
    pitch = pitch * PI / 180.0f;

    // Calculate roll (around z-axis)
    float roll = 0.0f; // Since you only have yaw and pitch, roll is assumed to be 0

    // Calculate pitch_new (around x-axis)
    float pitch_new = pitch;

    // Calculate yaw_new (around y-axis)
    float yaw_new = yaw;

    // Convert angles back to degrees if needed
    roll = roll * 180.0f / PI;
    pitch_new = pitch_new * 180.0f / PI;
    yaw_new = yaw_new * 180.0f / PI;

    return glm::vec3(roll, pitch_new, yaw_new);
}

void vmv::VecmathVisualizer::AddVariableDisplay(const std::string& id, IMatrix* pMatrix)
{
    Scalar* asScalar{dynamic_cast<Scalar*>(pMatrix)};
    if (asScalar != nullptr)
    {
        // if (id == "x" || id == "pitch")
        // {
        //     std::cout << "Moving on X\n";
        //     m_GameObjects[1].m_Transform.rotation.x += asScalar->get(0, 0);
        // }
        // else if (id == "y" || id == "yaw")
        // {
        //     std::cout << "Moving on Y\n";
        //     m_GameObjects[1].m_Transform.rotation.y += asScalar->get(0, 0);
        // }
        // else if (id == "z")
        // {
        //     std::cout << "Moving on Z\n";
        //     m_GameObjects[1].m_Transform.rotation.z += asScalar->get(0, 0);
        // }

        // std::cout << "xRot: " << m_GameObjects[1].m_Transform.rotation.x << "; "
        //           << "yRot: " << m_GameObjects[1].m_Transform.rotation.y << "; "
        //           << "zRot: " << m_GameObjects[1].m_Transform.rotation.z << '\n';
    }

    Vector3D* asVector3D{dynamic_cast<Vector3D*>(pMatrix)};
    if (asVector3D != nullptr)
    {
        VMVGameObject gameObject{VMVGameObject::CreateGameObject()};
        gameObject.m_Model = m_ArrowBodyModel;

        glm::vec3 initialVecDir{1, 0, 0};

        glm::vec3 pos{asVector3D->get(0, 0), asVector3D->get(0, 1), asVector3D->get(0, 2)};

        float r = std::sqrtf(pos.x * pos.x + pos.y * pos.y + pos.z * pos.z);

        float yAngle = std::acosf(pos.y / r);
        float xAngle = std::atan2f(pos.z, pos.x);
        std::cout << "y: " << yAngle << '\n';
        std::cout << "x: " << xAngle << '\n';

        gameObject.m_Transform.pitch = 3.1415f - yAngle;
        gameObject.m_Transform.yaw = xAngle;

        gameObject.m_Transform.scale.y = r;
        gameObject.m_Transform.onlyRotate = true;

        m_DisplayObjects[id] = &gameObject;

        m_ToAddNextFrame.push(std::move(gameObject));
    }
}

// GameObjects/Models loaded on construction
void vmv::VecmathVisualizer::Load()
{
    m_ArrowBodyModel = VMVModel::CreateModelFromFile(m_VMVDevice, "data/models/arrow_body.obj");

    std::shared_ptr<VMVModel> coordSystemModel{
        VMVModel::CreateModelFromFile(m_VMVDevice, "data/models/coordinate_system.obj")};

    VMVGameObject coordSystem{VMVGameObject::CreateGameObject()};
    coordSystem.m_Model = coordSystemModel;
    coordSystem.m_Transform.translation = {0.f, 0.f, 0.f};
    coordSystem.m_Transform.scale = {0.5f, 0.5f, 0.5f};

    m_GameObjects.push_back(std::move(coordSystem));

    // std::shared_ptr<VMVModel> model2{VMVModel::CreateModelFromFile(m_VMVDevice, "data/models/smooth_vase.obj")};
    // VMVGameObject gameObject2{VMVGameObject::CreateGameObject()};
    // gameObject2.m_Model = model2;
    // gameObject2.m_Transform.translation = {0.5f, 0.5f, 2.5f};
    // gameObject2.m_Transform.scale = {2.f, 2.f, 2.f};

    // m_GameObjects.push_back(std::move(gameObject2));

    // std::shared_ptr<VMVModel> model3{VMVModel::CreateModelFromFile(m_VMVDevice, "data/models/smooth_vase.obj")};
    // VMVGameObject gameObject3{VMVGameObject::CreateGameObject()};
    // gameObject3.m_Model = model3;
    // gameObject3.m_Transform.translation = {0.8f, 0.8f, 0.f};
    // gameObject3.m_Transform.scale = {2.f, 2.f, 2.f};

    // m_GameObjects2D.push_back(std::move(gameObject3));
}
