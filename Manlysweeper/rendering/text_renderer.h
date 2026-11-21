#pragma once

#include <memory>

#include "font.h"
#include "shader.h"

class TextRenderer
{
public:
    std::shared_ptr<Font> font{ nullptr };

    TextRenderer(const std::shared_ptr<Font>& font);
    ~TextRenderer();

    void RenderText(std::string text, float x, float y, float scale, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f), float anchorPointX = 0.0f, float anchorPointY = 0.0f) const;

    inline void SetViewportSize(float width, float height)
    {
        m_projectionMatrix = glm::ortho<float>(
            0.0f,
            width,
            0.0f,
            height,
            -1.0f,
            1.0f
        );
        m_glyphShader->Use();
        m_glyphShader->SetUniformMatrix(m_projectionLocation, m_projectionMatrix);
    }

    inline void SetViewportSize(const glm::vec2& windowSize)
    {
        this->SetViewportSize(windowSize.x, windowSize.y);
    }

private:
    GLuint m_vao = 0;
    GLuint m_vbo = 0;

    std::unique_ptr<Shader> m_glyphShader{ nullptr };
    GLint m_textColorLocation = 0;
    GLint m_projectionLocation = 0;

    glm::mat4 m_projectionMatrix = glm::mat4(1.0f);

    inline void CreateShader()
    {
        m_glyphShader = std::make_unique<Shader>("glyph", "assets/shaders/glyph_vert.glsl", "assets/shaders/glyph_frag.glsl");
        m_textColorLocation = m_glyphShader->GetUniformLocation("textColor");
        m_projectionLocation = m_glyphShader->GetUniformLocation("projection");
    }

};
