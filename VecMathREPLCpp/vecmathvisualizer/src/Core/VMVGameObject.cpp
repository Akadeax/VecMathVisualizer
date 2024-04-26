#include "VMVGameObject.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>

vmv::VMVGameObject vmv::VMVGameObject::CreateGameObject()
{
    static id_t currentId;
    return VMVGameObject(currentId++);
}

vmv::VMVGameObject::VMVGameObject(id_t id) : m_Id{id} {}

// Matrix corrsponds to Translate * Ry * Rx * Rz * Scale
// Rotations correspond to Tait-bryan angles of Y(1), X(2), Z(3)
// https://en.wikipedia.org/wiki/Euler_angles#Rotation_matrix
glm::mat4 vmv::Transform::GetMat() const
{
    if (onlyRotate)
    {
        // Create rotation matrix for yaw (around global y-axis)
        glm::mat4 yawMatrix = glm::rotate(glm::mat4(1.0f), -yaw, glm::vec3(0.0f, 1.0f, 0.0f));

        // Create rotation matrix for pitch (around local z-axis)
        glm::mat4 pitchMatrix = glm::rotate(glm::mat4(1.0f), -pitch, glm::vec3(0.0f, 0.0f, 1.0f));

        return yawMatrix * pitchMatrix * glm::scale(glm::mat4(1), scale);
    }

    const float c3 = glm::cos(-rotation.z);
    const float s3 = glm::sin(-rotation.z);
    const float c2 = glm::cos(-rotation.x);
    const float s2 = glm::sin(-rotation.x);
    const float c1 = glm::cos(-rotation.y);
    const float s1 = glm::sin(-rotation.y);
    return glm::mat4{{
                         scale.x * (c1 * c3 + s1 * s2 * s3),
                         scale.x * (c2 * s3),
                         scale.x * (c1 * s2 * s3 - c3 * s1),
                         0.0f,
                     },
                     {
                         -scale.y * (c3 * s1 * s2 - c1 * s3),
                         -scale.y * (c2 * c3),
                         -scale.y * (c1 * c3 * s2 + s1 * s3),
                         0.0f,
                     },
                     {
                         scale.z * (c2 * s1),
                         scale.z * (-s2),
                         scale.z * (c1 * c2),
                         0.0f,
                     },
                     {translation.x, translation.y, translation.z, 1.0f}};
}

glm::mat3 vmv::Transform::NormalMatrix() const
{
    return glm::mat3(1);
    // const float c3 = glm::cos(rotation.z);
    // const float s3 = glm::sin(rotation.z);
    // const float c2 = glm::cos(rotation.x);
    // const float s2 = glm::sin(rotation.x);
    // const float c1 = glm::cos(rotation.y);
    // const float s1 = glm::sin(rotation.y);

    // const glm::vec3 invScale = 1.f / scale;

    // return glm::mat3{{
    //                      invScale.x * (c1 * c3 + s1 * s2 * s3),
    //                      invScale.x * (c2 * s3),
    //                      invScale.x * (c1 * s2 * s3 - c3 * s1),
    //                  },
    //                  {
    //                      invScale.y * (c3 * s1 * s2 - c1 * s3),
    //                      invScale.y * (c2 * c3),
    //                      invScale.y * (c1 * c3 * s2 + s1 * s3),
    //                  },
    //                  {
    //                      invScale.z * (c2 * s1),
    //                      invScale.z * (-s2),
    //                      invScale.z * (c1 * c2),
    //                  }};
}
