#version 460 core

uniform sampler2D textureID;
uniform sampler2D overlayTextureID;

uniform int containsOverlay;

uniform vec3 tint;

in vec2 texCoord;

out vec4 fragColor;

void main()
{
    vec4 sampledBackground = texture2D(textureID, texCoord);
    vec4 sampledOverlay = texture2D(overlayTextureID, texCoord);
    float blend = sampledOverlay.a;
    if (containsOverlay == 0)
    {
        blend = 0.0;
    }
    fragColor = (sampledBackground + (sampledOverlay - sampledBackground) * blend) * vec4(tint, 1.0);
}
