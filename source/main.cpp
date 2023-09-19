#include <iostream>
#include <cassert>

#include <GLFW/glfw3.h>

const int width = 640;
const int height = 480;

int main()
{
	assert(glfwInit());

	GLFWwindow* window = glfwCreateWindow(width, height, "Blue Marble", nullptr, nullptr);
	assert(window);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}