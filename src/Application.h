#pragma once
#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "PerspectiveCamera.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace OGLE {
	class Application
	{
	public:
		Application();
		~Application();

		void Run();
		void ProcessInput(GLFWwindow* window);
		void MouseCallback(GLFWwindow* window, double xpos, double ypos);
		void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
		inline static Application& Get() { return *s_Instance; }
		inline GLFWwindow* GetWindow() { return m_Window; }

	private:
		static Application* s_Instance;

		GLFWwindow* m_Window;
		PerspectiveCamera m_Camera;
		const float WIDTH = 1440.f;
		const float HEIGHT = 900.f;
		float deltaTime = 0.0f;	// time between current frame and last frame
		float lastFrame = 0.0f;
	};
}