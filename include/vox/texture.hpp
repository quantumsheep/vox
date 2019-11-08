#pragma once

#include <vox/gl.hpp>

namespace Vox
{
class Texture
{
public:
    enum class Type
    {
        Depth,
        Diffuse,
        Specular,
    };

public:
    Type type;

    unsigned int id;

    unsigned int filter_minify;
    unsigned int filter_magnify;

    int width;
    int height;
    int channels_count;

    Texture(const char *path,
            Type type = Type::Diffuse,
            unsigned int filter_minify = GL_NEAREST_MIPMAP_LINEAR,
            unsigned int filter_magnify = GL_NEAREST_MIPMAP_LINEAR);

    void generate();

    void use(unsigned int index = 0);
};
} // namespace Vox
