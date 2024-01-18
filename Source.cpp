#include "Shader.h"
#include "SceneDrawer.h"
#include "InputController.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>


/************************************
*	CS-330							*
*	FINAL PROJECT					*
*	Justin Swinney					*
*************************************/

/*******************************************************************************************************************************/


	/**************************************************************************************************
	*																								  *
	*   MAIN																						  *
	*																								  *
	**************************************************************************************************/


int main() {

	if (!glfwInit()) {
		cout << "Failed to initialize GLFW" << endl;
		return -1;
	}

	// Create a GLFW window
	GLFWwindow* window = glfwCreateWindow(1200, 1200, "Final Project", NULL, NULL);
	if (!window) {
		cout << "Error creating GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); // Associating OpenGL rendering context with the pointer variable (window). Meaning all OpenGL rendering commans in this code will affect the pointer window. 

	// Initialize GLEW
	if (glewInit() != GLEW_OK) { // Initialization
		cout << "Failed to initialize GLEW" << endl;
		return -1; // If initialization fails terminate program and return -1.
	}


	// Memory leak fix below was creating shaders for each draw function causing memory leak. 
	GLuint shaderProgramID = createShaderProgram(vertexShaderSource, fragmentShaderSource);

	// MOVMENT 
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // DISABLE BEFORE SUBMITTING**
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetCursorPosCallback(window, mouse_callback);

	glEnable(GL_DEPTH_TEST);

	// Load Buffers
	SceneDrawer sceneDrawer;
	sceneDrawer.createBuffers();

	// Load Textures
	sceneDrawer.loadTextures();
	sceneDrawer.loadStandardKeyTextures(53);
	// Ambient settings
	glm::vec3 ambientLightColor = glm::vec3(1.0f, 1.0f, 1.0);
	float ambientLightIntensity = 0.4f;

	/**************************************************************************************************
	*																								  *
	*   MAIN LOOP																					  *
	*																								  *
	**************************************************************************************************/
	while (!glfwWindowShouldClose(window)) {

		//glClearColor(0.843f, 0.824f, 0.733f, 1.0f); // Tan color Background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
		glUseProgram(shaderProgramID);
		// AMBIENT LIGHT 
		glUniform3fv(glGetUniformLocation(shaderProgramID, "ambientLightColor"), 1, glm::value_ptr(ambientLightColor));
		glUniform1f(glGetUniformLocation(shaderProgramID, "ambientLightIntensity"), ambientLightIntensity);


		glm::mat4 view;
		glm::mat4 projection;

		switchViews(window);
		processInput(window);

		// 3D
		if (viewSwitch) {
			view = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
			projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
		}
		// 2D
		if (!viewSwitch) {
			float orthoSize = 2.0f; // ortho size galf width / height of ortho projection. 
			view = glm::lookAt(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Setting 2D front view
			projection = glm::ortho(-orthoSize, orthoSize, -orthoSize, orthoSize, 0.1f, 100.0f); // setting projection 
		}


		sceneDrawer.drawScene(shaderProgramID, view, projection);
	

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	sceneDrawer.cleanResources();
	glDeleteProgram(shaderProgramID);
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}