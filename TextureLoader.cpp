#include "TextureLoader.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint TextureLoader::loadTexture(const string& imagePath) {
    int width, height, numChannels;
    unsigned char* textureData = stbi_load(imagePath.c_str(), &width, &height, &numChannels, 0);

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    if (textureData) {
        GLenum format, internalFormat;
        // 1 channel image support 
        if (numChannels == 1) {
            format = GL_RED;
            internalFormat = GL_R8;  
        }
        // 3 channel image support 
        else if (numChannels == 3) {
            format = GL_RGB;
            internalFormat = GL_RGB;
        }
        // 4 channel image support 
        else if (numChannels == 4) {
            format = GL_RGBA;
            internalFormat = GL_RGBA;
        }
        else {
            stbi_image_free(textureData);
            cout << "Unsupported number of channels: " << numChannels << endl;
            return -1;
        }

        stbi_set_flip_vertically_on_load(true);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(textureData);
    }
    else {
        cout << "Failed to load texture." << endl;
        return -1;
    }
    return textureID;
}
