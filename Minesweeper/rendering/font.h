#pragma once

#include <memory>
#include <format>
#include <print>
#include <mutex>

#include <glm/glm.hpp>
#include <mgl.h>

#include <ft2build.h>
#include FT_FREETYPE_H

struct Glyph
{
    unsigned int textureID;
    glm::ivec2 size;
    glm::ivec2 bearing;
    unsigned int advance;
};

class Font
{
private:
    static constexpr double inchesToPoint = 72.0;
    static constexpr double pointsToInches = 1.0 / inchesToPoint;

public:
    Font(const char* filename)
    {
        m_filename = filename;
        m_size = 14.0f;
        m_dpi = glm::vec2(300.0f, 300.0f);
        CalculateConversions();
        LoadFont();
    }

    inline void SetSize(float size)
    {
        m_size = size;
        ReloadFont();
    }

    inline constexpr float GetSize() const noexcept
    {
        return m_size;
    }

    inline void SetDPI(const glm::vec2& dpi)
    {
        m_dpi = dpi;
        CalculateConversions();
        ReloadFont();
    }

    inline constexpr glm::vec2 GetDPI() const noexcept
    {
        return m_dpi;
    }

    inline constexpr const Glyph* GetGlyph(int character) const
    {
        auto it = m_glyphs.find(character);
        if (it == m_glyphs.end()) throw std::runtime_error(std::format("Failed to get glyph for character: {}", static_cast<char>(character)));
        return it->second.get();
    }

    inline constexpr float PointToPixelsX(float point) const noexcept
    {
        return point * m_pointToPixels.x;
    }

    inline constexpr float PointToPixelsY(float point) const noexcept
    {
        return point * m_pointToPixels.y;
    }

    inline constexpr float PixelsToPointX(float pixels) const noexcept
    {
        return pixels / m_pointToPixels.x;
    }

    inline constexpr float PixelsToPointY(float pixels) const noexcept
    {
        return pixels / m_pointToPixels.y;
    }

private:
    std::mutex m_glyphMutex;
    std::unordered_map<int, std::unique_ptr<Glyph>> m_glyphs;

    const char* m_filename;
    float m_size;
    glm::vec2 m_dpi;
    glm::vec2 m_pointToPixels;
    glm::vec2 m_pixelsToPoint;

    void CalculateConversions() noexcept
    {
        m_pointToPixels = glm::vec2(m_dpi.x * pointsToInches, m_dpi.y * pointsToInches);
        m_pixelsToPoint = glm::vec2(m_dpi.x / pointsToInches, m_dpi.y / pointsToInches);
    }

    void ReloadFont()
    {
        UnloadFont();
        LoadFont();
    }

    void UnloadFont() noexcept
    {
        if (m_glyphs.size() > 0)
        {
            for (auto& [character, glyph] : m_glyphs)
            {
                glDeleteTextures(1, &glyph->textureID);
            }
        }
        m_glyphs.clear();
    }

    void LoadFont()
    {
        if (m_size <= 0.0f) return;

        std::lock_guard<std::mutex> lock(m_glyphMutex);

        FT_Library library;

        FT_Error error = FT_Init_FreeType(&library);
        if (error)
        {
            throw std::runtime_error(std::format("Failed to initialize FreeType: {}", FT_Error_String(error)));
        }

        FT_Face face;
        error = FT_New_Face(library, "assets/fonts/VCR_MONO.ttf", 0, &face);
        if (error == FT_Err_Unknown_File_Format)
        {
            throw std::runtime_error("Font was able to be loaded but is an unsupported format.");
        }
        else if (error)
        {
            throw std::runtime_error(std::format("Failed to load font: {}", FT_Error_String(error)));
        }

        error = FT_Set_Char_Size(face, 0, m_size * 64, m_dpi.x, m_dpi.y);

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        for (unsigned char c = 0; c < 128; ++c)
        {
            if (FT_Load_Char(face, c, FT_LOAD_RENDER))
            {
                std::println(stderr, "Failed to load glyph", static_cast<char>(c));
                continue;
            }

            GLuint texture;
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,
                GL_RED,
                GL_UNSIGNED_BYTE,
                face->glyph->bitmap.buffer
            );
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

            std::unique_ptr<Glyph> character = std::make_unique<Glyph>(
                texture,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                face->glyph->advance.x
            );
            m_glyphs.insert(std::make_pair(c, std::move(character)));
        }

        FT_Done_Face(face);
        FT_Done_FreeType(library);
    }

};
