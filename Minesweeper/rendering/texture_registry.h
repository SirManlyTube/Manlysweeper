#pragma once

#include <unordered_map>
#include <memory>
#include <cassert>

#include "texture.h"

class TextureRegistry
{
public:
    inline constexpr const std::unique_ptr<Texture>& GetTexture(int id) const
    {
        auto it = m_textures.find(id);
        assert(it != m_textures.end() && "ID not found in texture registry!");
        return it->second;
    }

    inline void RegisterTexture(int id, std::unique_ptr<Texture> texture) noexcept
    {
        m_textures[id] = std::move(texture);
    }

private:
    std::unordered_map<int, std::unique_ptr<Texture>> m_textures;

};

extern void SetGlobalTextureRegistry(const std::shared_ptr<TextureRegistry>& textureRegistry) noexcept;
extern std::shared_ptr<TextureRegistry>& GetGlobalTextureRegistry() noexcept;
