#pragma once

#include <string>

class Shader {
public:
    unsigned int ID;

    // Constructor
    Shader(const char* vertexPath, const char* fragmentPath);

    // Activate shader
    void use();

    // Uniform setters
    void setInt(const std::string& name, int value);
    void setFloat(const std::string& name, float value);
};