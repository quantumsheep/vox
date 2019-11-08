#include <vox/texture.hpp>

#include <vox/log.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Vox::Texture::Texture(const char *path, Type type_, unsigned int filter_minify_, unsigned int filter_magnify_)
    : type(type_),
      filter_minify(filter_minify_),
      filter_magnify(filter_magnify_)
{
    this->generate();

    if (unsigned char *data = stbi_load(path, &this->width, &this->height, &this->channels_count, 0))
    {
        unsigned int format = (this->channels_count == 4) ? GL_RGBA : GL_RGB;

        glTexImage2D(GL_TEXTURE_2D, 0, format, this->width, this->height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }
    else
    {
        Vox::Log(std::string("Failed to load texture: ") + path);
    }
}

void Vox::Texture::generate()
{
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filter_minify);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filter_magnify);
}

void Vox::Texture::use(unsigned int index)
{
    if (this->type == Texture::Type::Depth)
    {
        glDrawBuffer(GL_NONE);
    }

    glActiveTexture(GL_TEXTURE0 + index);
    glBindTexture(GL_TEXTURE_2D, this->id);
}
