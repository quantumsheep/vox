#pragma once

#include <vox/texture.hpp>
#include <vox/vertex.hpp>

#include <assimp/scene.h>

#include <vector>

namespace Vox
{
class Mesh
{
private:
    bool have_indices = true;

public:
    std::vector<Vox::Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Vox::Texture> textures;

    unsigned int vbo;
    unsigned int vao;
    unsigned int ebo;

    Mesh(aiMesh *mesh, const aiScene *scene);

    Mesh(std::vector<Vox::Vertex> vertices);
    Mesh(std::vector<Vox::Vertex> vertices, std::vector<unsigned int> indices);

    void render();
    void draw();
};
} // namespace Vox
