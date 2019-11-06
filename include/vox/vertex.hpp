#pragma once

#include <vox/gl.hpp>

namespace Vox
{
struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texture_coordinates;
    glm::vec3 tangent;
    glm::vec3 bitangent;
};
} // namespace Vox
