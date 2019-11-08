#include <vox/model.hpp>

#include <vox/log.hpp>

Vox::Model::Model(std::string path)
{
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        Vox::Log(importer.GetErrorString());
        return;
    }

    this->process_node(scene->mRootNode, scene);
}

void Vox::Model::process_node(aiNode *node, const aiScene *scene)
{
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        Vox::Mesh mesh(scene->mMeshes[node->mMeshes[i]], scene);
        this->meshes.push_back(mesh);
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        process_node(node->mChildren[i], scene);
    }
}

void Vox::Model::draw()
{
    for (auto &mesh : this->meshes)
    {
        mesh.draw();
    }
}
