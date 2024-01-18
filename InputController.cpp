#include "InputController.h"


glm::vec3 cameraPosition = glm::vec3(0.0f, 1.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
float cameraSpeed = 0.05f;
float lastX = 400;
float lastY = 300;
float yaw = -90.0f;
float pitch = 0.0f;
bool firstMouse = true;
bool viewSwitch = true;
bool p_released = true;

void processInput(GLFWwindow* window) {
	// W = FORWARD
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		cameraPosition += cameraSpeed * cameraFront;
	}
	// S = BACKWARDS
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		cameraPosition -= cameraSpeed * cameraFront;
	}
	// A = LEFT
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	}
	// D = RIGHT
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	}

	// Q = UP 
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		cameraPosition += cameraSpeed * cameraUp;
	}
	// E = DOWN
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		cameraPosition -= cameraSpeed * cameraUp;
	}
}

// Mouse Direction

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.2f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);
}


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	cameraSpeed += static_cast<float>(yoffset) * 0.01f;
	if (cameraSpeed < 0.01f) {
		cameraSpeed = 0.01f;
	}
	else if (cameraSpeed > 1.0f) {
		cameraSpeed = 1.0f;
	}
}

void switchViews(GLFWwindow* window) {
	// switch key
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && p_released) { // ensures view is switch to opposite true/ false of itself and p_release to avoid multiple inputs caused by while loop
		viewSwitch = !viewSwitch;
		p_released = false;
	}
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_RELEASE) { // while loop handle.
		p_released = true;
	}


}

