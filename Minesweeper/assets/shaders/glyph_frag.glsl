#version 460 core

uniform sampler2D text;
uniform vec3 textColor;

in vec2 texCoords;

out vec4 fragColor;

void main()
{
    vec4 sampled = vec4(1.0, 1.0, 1.0, texture2D(text, texCoords).r);
    fragColor = vec4(textColor, 1.0) * sampled;
}
