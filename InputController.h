#pragma once

#include <glm/fwd.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

extern glm::vec3 cameraPosition;
extern glm::vec3 cameraFront;
extern glm::vec3 cameraUp;
extern float cameraSpeed;
extern float lastX;
extern float lastY;
extern float yaw;
extern float pitch;
extern bool firstMouse;
extern bool viewSwitch;
extern bool p_released;

void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void switchViews(GLFWwindow* window);