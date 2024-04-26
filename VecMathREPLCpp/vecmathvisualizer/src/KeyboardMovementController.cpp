#include "KeyboardMovementController.h"

#include <glm/gtc/constants.hpp>

void vmv::KeyboardMovementController::MoveInPlaneXZ(GLFWwindow* window, float dt, VMVGameObject& go)
{
    float inputYaw{}, inputPitch{};

    if (glfwGetKey(window, keys.lookRight) == GLFW_PRESS)
        inputPitch += 1.f;
    if (glfwGetKey(window, keys.lookLeft) == GLFW_PRESS)
        inputPitch -= 1.f;
    if (glfwGetKey(window, keys.lookUp) == GLFW_PRESS)
        inputYaw += 1.f;
    if (glfwGetKey(window, keys.lookDown) == GLFW_PRESS)
        inputYaw -= 1.f;

    if (inputYaw != 0)
        go.m_Transform.yaw += inputYaw * dt * lookSpeed;
    if (inputPitch != 0)
        go.m_Transform.pitch += inputPitch * dt * lookSpeed;

    const glm::vec3 forward{std::sinf(go.m_Transform.pitch), 0.f, std::cosf(go.m_Transform.pitch)};
    const glm::vec3 right{forward.z, 0.f, -forward.x};
    const glm::vec3 up{0.f, -1.f, 0.f};

    glm::vec3 moveDir{0.f};
    if (glfwGetKey(window, keys.moveForward) == GLFW_PRESS)
        moveDir += forward;
    if (glfwGetKey(window, keys.moveBackward) == GLFW_PRESS)
        moveDir -= forward;
    if (glfwGetKey(window, keys.moveRight) == GLFW_PRESS)
        moveDir += right;
    if (glfwGetKey(window, keys.moveLeft) == GLFW_PRESS)
        moveDir -= right;
    if (glfwGetKey(window, keys.moveUp) == GLFW_PRESS)
        moveDir += up;
    if (glfwGetKey(window, keys.moveDown) == GLFW_PRESS)
        moveDir -= up;

    if (glm::dot(moveDir, moveDir) > std::numeric_limits<float>::epsilon())
        go.m_Transform.translation += moveSpeed * dt * glm::normalize(moveDir);
}