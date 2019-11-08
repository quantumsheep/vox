#pragma once

#include <vox/mesh.hpp>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <string>

namespace Vox
{
class Model
{
public:
    std::vector<Vox::Mesh> meshes;

    Model(std::string path);
    Model(std::vector<Vox::Mesh> meshes_) : meshes(meshes_) {}
    Model(Vox::Mesh mesh) : meshes({mesh}) {}

    void draw();

private:
    void process_node(aiNode *node, const aiScene *scene);
};
} // namespace Vox
