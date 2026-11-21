#pragma once

#include <stdexcept>
#include <format>

#include <mgl.h>

class Texture
{
public:
    Texture(const char* texturePath);

    ~Texture()
    {
        glDeleteTextures(1, &m_id);
    }

    inline constexpr GLuint GetID() const
    {
        return m_id;
    }

private:
    GLuint m_id = 0;

};
