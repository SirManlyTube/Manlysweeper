#define STBI_ONLY_BMP
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "texture.h"

Texture::Texture(const char* texturePath)
{
    stbi_set_flip_vertically_on_load(true);

    glGenTextures(1, &m_id);

    if (m_id == 0)
    {
        throw std::runtime_error(std::format("Could not create GL texture for texture '{}'.", texturePath));
    }

    glBindTexture(GL_TEXTURE_2D, m_id);

    int width, height, channels;
    unsigned char* data = stbi_load(texturePath, &width, &height, &channels, STBI_rgb_alpha);

    if (data == nullptr)
    {
        throw std::runtime_error(std::format("Could not load texture '{}': {}", texturePath, stbi_failure_reason()));
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    stbi_image_free(data);
}
