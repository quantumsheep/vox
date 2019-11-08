#include <vox/camera.hpp>

glm::mat4 Vox::Camera::view() const
{
    glm::quat pitch = glm::angleAxis(glm::radians(this->rotation.y), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::quat yaw = glm::angleAxis(glm::radians(this->rotation.x + 180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::quat roll = glm::angleAxis(glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::quat orientation = pitch * yaw * roll;
    orientation = glm::normalize(orientation);

    glm::mat4 rotate = glm::mat4_cast(orientation);

    glm::mat4 translate = glm::mat4(1.0f);
    translate = glm::translate(translate, -this->position);

    return rotate * translate;
}

glm::mat4 Vox::Camera::projection() const
{
    return glm::perspective(glm::radians(this->fov), this->aspect, this->near, this->far);
}
