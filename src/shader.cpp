#include <vox/shader.hpp>

#include <vox/log.hpp>

#include <fstream>

Vox::Shader::Shader(std::string vertex_path, std::string fragment_path)
{
    if (char *err = this->load_glsl_file(vertex_path, this->vertex_source, this->vertex_shader))
        Vox::Log(err);

    if (char *err = this->load_glsl_file(fragment_path, this->fragment_source, this->fragment_shader))
        Vox::Log(err);

    if (char *err = this->create_program({this->vertex_shader, this->fragment_shader}))
        Vox::Log(err);

    glDeleteShader(this->vertex_shader);
    glDeleteShader(this->fragment_shader);
}

char *Vox::Shader::create_program(std::vector<unsigned int> shaders)
{
    this->program = glCreateProgram();

    for (auto &shader : shaders)
    {
        glAttachShader(this->program, shader);
    }

    glLinkProgram(this->program);

    int success;
    glGetProgramiv(this->program, GL_LINK_STATUS, &success);

    char *err = nullptr;
    if (!success)
    {
        err = new char[512];
        glGetProgramInfoLog(this->program, 512, NULL, err);
    }

    return err;
}

static std::string read_file(std::string path)
{
    std::ifstream f(path);
    std::string str;

    /* Reserve specific amount of bytes for receiving the GLSL sources */
    f.seekg(0, std::ios::end);
    str.reserve(f.tellg());
    f.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

    return str;
}

char *Vox::Shader::load_glsl_file(std::string path, char *&source_dest, unsigned int &shader_dest)
{
    std::string source = read_file(path);
    source_dest = new char[source.length() + 1];
    std::strcpy(source_dest, source.c_str());

    glShaderSource(shader_dest, 1, &source_dest, NULL);
    glCompileShader(shader_dest);

    int success;
    glGetShaderiv(shader_dest, GL_COMPILE_STATUS, &success);

    char *err = nullptr;
    if (!success)
    {
        err = new char[512];
        glGetShaderInfoLog(shader_dest, 512, NULL, err);
    }

    return err;
}