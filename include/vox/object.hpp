#pragma once

#include <vox/gl.hpp>
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

    std::vector<Vertex> vertices;

    unsigned int vbo;
    unsigned int vao;
    unsigned int ebo;

    Object(std::vector<Vertex> vertices,
           glm::vec3 position = glm::vec3(0.0f),
           glm::vec3 rotation = glm::vec3(0.0f),
           glm::vec3 scale = glm::vec3(1.0f));

    virtual glm::mat4 model();
    virtual void draw();
};
} // namespace Vox
