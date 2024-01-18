#pragma once
#include <GL/glew.h>
#include <cstddef>

unsigned int createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
extern const char* vertexShaderSource;
extern const char* fragmentShaderSource;