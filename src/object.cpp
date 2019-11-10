#include <vox/object.hpp>

glm::mat4 Vox::Object::model_matrix()
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, this->position);
    model = glm::rotate(model, glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(this->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, this->scale);

    return model;
}

Vox::Object::Object(Vox::Model model_, glm::vec3 position_, glm::vec3 rotation_, glm::vec3 scale_, bool visible_)
    : model(model_),
      position(position_),
      rotation(rotation_),
      scale(scale_),
      visible(visible_)
{
}

void Vox::Object::draw()
{
    if (this->visible)
    {
        this->model.draw();
    }
}
