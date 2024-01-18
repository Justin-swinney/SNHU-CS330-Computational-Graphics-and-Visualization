#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Buffers.h"
#include "MeshData.h"
#include <string>
#include "TextureLoader.h"
#include <iostream>
#include <GLFW/glfw3.h>


class SceneDrawer {
public:
    static void loadTextures();
    static void loadStandardKeyTextures(int numTextures);
    static void createBuffers();
    static void drawDesk(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawKeyboard(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawSpacebar(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawSmallKeys(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, float finalX, float increment, int textureIndexStart);
    static void drawMediumKeys(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, GLuint textureID);
    static void drawRow1(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawRow2(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawRow3(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawRow4(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawRow5(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawLightTest(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawScene(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawMonitor(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, string rotate, GLuint texture);
    static void drawMonitorScreen(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, string rotate, GLuint texture);
    static void drawMacBook(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawCylinder(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawMouseBody(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, float roatationDegrees, const glm::vec3& rotationAxis, GLuint texture);
    static void drawTorus(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, float roatationDegree, GLuint texture);
    static void drawMonitorMount(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection);
    static void drawCube(GLuint shaderProgramID, glm::mat4 view, glm::mat4 projection, const glm::vec3& scale, const glm::vec3& translation, float roatationDegree, GLuint texture);
    static void cleanResources();
   
private:
    
    static GLuint deskTextureID;
    static GLuint keyboardTextureID;
    static GLuint keysTextureID;
    static GLuint spacebarTextureID;
    static GLuint shiftTextureID;
    static GLuint enterTextureID;
    static GLuint capsTextureID;
    static GLuint backspaceTextureID;
    static GLuint backslashTextureID;
    static GLuint tabTextureID;
    static GLuint leftMonitorTextureID;
    static GLuint centerMonitorTextureID;
    static GLuint rightMonitorTextureID;
    static GLuint macBookTextureID;
    static GLuint mouseTopTextureID;
    static GLuint monitorMountTextureID;
    static vector<string> texFileNames;
    static vector<GLuint> textureIDs;
    static void setUniformMatrix4fv(GLuint shaderProgramID, const char* uniformName, glm::mat4 matrix);
};

