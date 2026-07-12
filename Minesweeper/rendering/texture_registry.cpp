#include "texture_registry.h"

static std::shared_ptr<TextureRegistry> g_textureRegistry;

void SetGlobalTextureRegistry(const std::shared_ptr<TextureRegistry>& textureRegistry) noexcept
{
    g_textureRegistry = textureRegistry;
}

std::shared_ptr<TextureRegistry>& GetGlobalTextureRegistry() noexcept
{
    return g_textureRegistry;
}
