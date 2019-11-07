#include <vox/camera.hpp>

glm::mat4 Vox::Camera::view() const
{
    glm::mat4 model(1.0f);
    model = glm::rotate(model, glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(this->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

    return model * glm::translate(glm::mat4(1.0f), this->position);
}

glm::mat4 Vox::Camera::projection() const
{
    return glm::perspective(glm::radians(this->fov), this->aspect, this->near, this->far);
}
