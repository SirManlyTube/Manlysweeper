#pragma once

#include <print>
#include <string>
#include <format>
#include <fstream>
#include <stdexcept>

#include <unordered_map>

#include <mgl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    Shader() = default;

    Shader(const std::string& name, const char* vertexShaderPath, const char* fragmentShaderPath) : m_name(name), m_program(glCreateProgram())
    {
        if (m_program == 0) throw std::runtime_error("Failed to create shader program!");

        CompileShader(GL_VERTEX_SHADER, vertexShaderPath);
        CompileShader(GL_FRAGMENT_SHADER, fragmentShaderPath);

        LinkProgram();
    }

    ~Shader()
    {
        if (m_program != 0) glDeleteProgram(m_program);
    }

    inline void Use() const
    {
        glUseProgram(m_program);
    }

    inline constexpr GLint GetUniformLocation(const char* name)
    {
        auto it = m_uniformLocations.find(name);
        if (it != m_uniformLocations.end()) return it->second;
        GLint location = glGetUniformLocation(m_program, name);
        m_uniformLocations[name] = location;
        return location;
    }

    inline void SetUniformMatrix(GLint location, const glm::mat4& matrix) const
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    inline void SetUniformVector(GLint location, const glm::vec3& vector) const
    {
        glUniform3fv(location, 1, glm::value_ptr(vector));
    }

    inline void SetUniformInt(GLint location, int value) const
    {
        glUniform1i(location, value);
    }

private:
    std::string m_name = "";
    GLuint m_program = 0;

    std::unordered_map<const char*, GLint> m_uniformLocations;

    void CompileShader(GLenum shaderType, const char* filename) const;
    void LinkProgram();

};
