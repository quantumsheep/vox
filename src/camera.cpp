#include <vox/camera.hpp>

glm::mat4 Vox::Camera::view() const
{
    glm::vec3 front(
        cos(glm::radians(this->rotation.y)) * cos(glm::radians(this->rotation.x + 90.0f)),
        sin(glm::radians(this->rotation.y)),
        cos(glm::radians(this->rotation.y)) * sin(glm::radians(this->rotation.x + 90.0f)));

    return glm::lookAt(this->position, this->position + glm::normalize(front), glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Vox::Camera::projection() const
{
    return glm::perspective(glm::radians(this->fov), this->aspect, this->near, this->far);
}
