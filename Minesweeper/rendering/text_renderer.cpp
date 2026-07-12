#include "text_renderer.h"

#include <mgl.h>

TextRenderer::TextRenderer(const std::shared_ptr<Font>& font) : font(font)
{
    glGenVertexArrays(1, &m_vao);
    if (m_vao == 0)
    {
        throw std::runtime_error("Failed to create text VAO");
    }
    glGenBuffers(1, &m_vbo);
    if (m_vbo == 0)
    {
        throw std::runtime_error("Failed to create text VBO");
    }
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, nullptr, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    CreateShader();
}

TextRenderer::~TextRenderer()
{
    if (m_vao != 0) glDeleteVertexArrays(1, &m_vao);
    if (m_vbo != 0) glDeleteBuffers(1, &m_vbo);
}

void TextRenderer::RenderText(std::string text, float x, float y, float scale, glm::vec3 color, float anchorPointX, float anchorPointY) const
{
    float fontSize = font->GetSize();
    if (font->GetSize() <= 0.0f) return;
    m_glyphShader->Use();
    m_glyphShader->SetUniformVector(m_textColorLocation, color);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(m_vao);

    std::string formattedText;

    size_t lineCount = 0;
    int column = 0;

    for (auto c = text.begin(); c != text.end(); ++c)
    {
        if (*c == '\n')
        {
            lineCount += 1;
            formattedText += '\n';
            column = 0;
            continue;
        }
        else if (*c == '\t')
        {
            int spacesToInsert = 4 - (column % 4);
            column += spacesToInsert;
            for (int i = 0; i < spacesToInsert; ++i)
            {
                formattedText += ' ';
            }
            continue;
        }

        formattedText += *c;
        column += 1;
    }

    float tallestLetterHeight = 0.0f;
    float longestLineWidth = 0.0f;
    float totalWidth = 0.0f;
    float totalHeight = font->PointToPixelsY(fontSize) * scale;

    formattedText.reserve(text.size());

    for (auto c = formattedText.begin(); c != formattedText.end(); ++c)
    {
        if (*c == '\n')
        {
            if (totalWidth > longestLineWidth)
            {
                longestLineWidth = totalWidth;
            }
            totalWidth = 0.0f;
            totalHeight += font->PointToPixelsY(fontSize) * scale;
            tallestLetterHeight = 0.0f;

            continue;
        }
        const Glyph* glyph = font->GetGlyph(*c);

        float width = glyph->size.x * scale;
        float height = glyph->size.y * scale;

        totalWidth += (glyph->advance >> 6) * scale;
    }

    if (totalWidth > longestLineWidth)
    {
        longestLineWidth = totalWidth;
    }
    totalHeight += tallestLetterHeight;

    x -= longestLineWidth * anchorPointX;

    float initialX = x;
    y -= totalHeight * anchorPointY;

    for (auto c = formattedText.begin(); c != formattedText.end(); ++c)
    {
        if (*c == '\n')
        {
            lineCount -= 1;
            x = initialX;
            continue;
        }
        const Glyph* glyph = font->GetGlyph(*c);

        float xPos = x + glyph->bearing.x * scale;
        float yPos = (y + static_cast<float>(lineCount) * font->PointToPixelsY(fontSize) * scale) - static_cast<float>(glyph->size.y - glyph->bearing.y) * scale;

        float width = glyph->size.x * scale;
        float height = glyph->size.y * scale;
        float vertices[6][4] = {
            { xPos,             yPos + height,  0.0f, 0.0f },
            { xPos,             yPos,           0.0f, 1.0f },
            { xPos + width,     yPos,           1.0f, 1.0f },
            { xPos,             yPos + height,  0.0f, 0.0f },
            { xPos + width,     yPos,           1.0f, 1.0f },
            { xPos + width,     yPos + height,  1.0f, 0.0f },
        };

        glBindTexture(GL_TEXTURE_2D, glyph->textureID);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        x += (glyph->advance >> 6) * scale;
    }

    glBindVertexArray(0);
}
