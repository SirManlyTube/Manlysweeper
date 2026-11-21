#include "shader.h"

void Shader::CompileShader(GLenum shaderType, const char* filename) const
{
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open())
    {
        throw std::runtime_error(std::format("Failed to open shader '{}' for reading.", filename));
    }

    GLuint shader = glCreateShader(shaderType);

    size_t vertexShaderLength = static_cast<size_t>(file.tellg());
    file.seekg(0);

    std::string code;
    code.resize(vertexShaderLength);

    file.read(code.data(), vertexShaderLength);

    const char* source = code.c_str();

    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        glDeleteShader(shader);
        throw std::runtime_error(std::format("Failed to compile vertex shader for shader '{}': {}", m_name, infoLog));
    }

    glAttachShader(m_program, shader);

    glDeleteShader(shader);
}

void Shader::LinkProgram()
{
    glLinkProgram(m_program);

    int success;
    glGetProgramiv(m_program, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(m_program, 512, nullptr, infoLog);
        throw std::runtime_error(std::format("Failed to link shader program for shader '{}': {}", m_name, infoLog));
    }
}
