#pragma once
#include <GL/glew.h>
#include <vector>
#include <iostream>
using namespace std;

class Buffer {
public:
	static void createBuffer(GLuint& VAO, GLuint& VBO, GLuint& EBO, const vector<GLfloat>& vertices, const vector<GLuint>& indices);
};