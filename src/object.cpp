#include <vox/object.hpp>

glm::mat4 Vox::Object::model()
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, this->position);
    model = glm::rotate(model, glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(this->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, this->scale);

    return model;
}

Vox::Object::Object(std::vector<Vertex> vertices_, glm::vec3 position_, glm::vec3 rotation_, glm::vec3 scale_)
    : vertices(vertices_),
      position(position_),
      rotation(rotation_),
      scale(scale_)
{
    glGenVertexArrays(1, &this->vao);
    glGenBuffers(1, &this->vbo);
    // glGenBuffers(1, &this->ebo);

    glBindVertexArray(this->vao);

    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, texture_coordinates));

    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, tangent));

    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, bitangent));

    glBindVertexArray(0);
}