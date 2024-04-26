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

glm::mat4 vmv::Transform::GetMat() const
{
    glm::mat4 translateMatrix = glm::translate(glm::mat4(1), translation);

    glm::mat4 yawMatrix = glm::rotate(glm::mat4(1.0f), -yaw, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 pitchMatrix = glm::rotate(glm::mat4(1.0f), -pitch, glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 scaleMatrix = glm::scale(glm::mat4{1}, scale);

    return translateMatrix * yawMatrix * pitchMatrix * scaleMatrix;
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
