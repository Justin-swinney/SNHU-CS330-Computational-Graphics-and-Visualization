#pragma once
#include <GL/glew.h>
#include <string>
using namespace std;

class TextureLoader {
public:
	static GLuint loadTexture(const string& imagePath);
};