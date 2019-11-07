#include <vox/camera.hpp>

glm::mat4 Vox::Camera::view() const
{
    glm::quat rotation_matrix(glm::vec3(
        glm::radians(this->rotation.x),
        glm::radians(this->rotation.y),
        glm::radians(this->rotation.z)));

    return glm::mat4_cast(rotation_matrix) * glm::translate(glm::mat4(1.0f), this->position);
}

glm::mat4 Vox::Camera::projection() const
{
    return glm::perspective(glm::radians(this->fov), this->aspect, this->near, this->far);
}
