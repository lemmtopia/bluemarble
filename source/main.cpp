#include <iostream>
#include <cassert>
#include <array>

// ALWAYS INCLUDE GLEW BEFORE GLFW
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

const int width = 640;
const int height = 480;

int main()
{
	assert(glfwInit());
	
	GLFWwindow* window = glfwCreateWindow(width, height, "Blue Marble", nullptr, nullptr);
	assert(window);

	glfwMakeContextCurrent(window);
	assert(glewInit() == GLEW_OK);

	// It's quite useful to get GL version and vendor.
	GLint majorVersion = 0;
	GLint minorVersion = 0;
	glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &minorVersion);
	
	std::cout << "OpenGL Version: " << majorVersion << "." << minorVersion << std::endl;
	std::cout << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;

	// Triangle definitions
	// stc::array<type, size> name = {};
	std::array<glm::vec3, 3> triangle = {
		glm::vec3( -1.0f, -1.0f, 0.0f ),
		glm::vec3(  1.0f, -1.0f, 0.0f ),
		glm::vec3(  0.0f,  1.0f, 0.0f )
	};

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); // Buffer prepwork

	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle.data(), GL_STATIC_DRAW); // Copying the triangle to the vertex buffer

	glClearColor(0, 1, 1, 1); // Awful cyan yay

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

		glDrawArrays(GL_TRIANGLES, 0, 3); // GG Easy

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}