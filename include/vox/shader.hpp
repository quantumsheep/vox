#pragma once

#include <vox/gl.hpp>

#include <string>
#include <vector>

namespace Vox
{
class Shader
{
public:
    unsigned int program = 0;

    char *vertex_source = nullptr;
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    char *fragment_source = nullptr;
    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

private:
    char *load_glsl_file(std::string path, char *&source_dest, unsigned int &shader_dest);

public:
    Shader(std::string vertex_path, std::string fragment_path);

    inline void use() const
    {
        glUseProgram(this->program);
    }

    char *create_program(std::vector<unsigned int> shaders);

    inline void set_bool(const std::string &name, bool value) const
    {
        glUniform1i(glGetUniformLocation(this->program, name.c_str()), (int)value);
    }

    inline void set_int(const std::string &name, int value) const
    {
        glUniform1i(glGetUniformLocation(this->program, name.c_str()), value);
    }

    inline void set_float(const std::string &name, float value) const
    {
        glUniform1f(glGetUniformLocation(this->program, name.c_str()), value);
    }

    inline void set_vec2(const std::string &name, const glm::vec2 &value) const
    {
        glUniform2fv(glGetUniformLocation(this->program, name.c_str()), 1, &value[0]);
    }

    inline void set_vec2(const std::string &name, float x, float y) const
    {
        glUniform2f(glGetUniformLocation(this->program, name.c_str()), x, y);
    }

    inline void set_vec3(const std::string &name, const glm::vec3 &value) const
    {
        glUniform3fv(glGetUniformLocation(this->program, name.c_str()), 1, &value[0]);
    }

    inline void set_vec3(const std::string &name, float x, float y, float z) const
    {
        glUniform3f(glGetUniformLocation(this->program, name.c_str()), x, y, z);
    }

    inline void set_vec4(const std::string &name, const glm::vec4 &value) const
    {
        glUniform4fv(glGetUniformLocation(this->program, name.c_str()), 1, &value[0]);
    }

    inline void set_vec4(const std::string &name, float x, float y, float z, float w)
    {
        glUniform4f(glGetUniformLocation(this->program, name.c_str()), x, y, z, w);
    }

    inline void set_mat2(const std::string &name, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(this->program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    inline void set_mat3(const std::string &name, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(this->program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    inline void set_mat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(this->program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
};
} // namespace Vox
