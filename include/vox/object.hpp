#pragma once

#include <vox/gl.hpp>
#include <vox/model.hpp>
#include <vox/vertex.hpp>

#include <vector>

namespace Vox
{
class Object
{
public:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    Vox::Model model;

    Object(Vox::Model model,
           glm::vec3 position = glm::vec3(0.0f),
           glm::vec3 rotation = glm::vec3(0.0f),
           glm::vec3 scale = glm::vec3(1.0f));

    virtual glm::mat4 model_matrix();
    virtual void draw();
};
} // namespace Vox
