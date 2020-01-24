#pragma once

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Window.h"
#include "Entities/Entity.h"
#include "Entities/PerspectiveCamera.h"

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
		inline Window* GetWindow() { return m_Window.get(); }

	private:
		static Application* s_Instance;

		Scope<Window> m_Window;
		//Scope<Renderer> m_Renderer;
		PerspectiveCamera m_Camera;
		std::vector<Entity*> m_Entities;
		const float WIDTH = 800.f;
		const float HEIGHT = 600.f;
		float deltaTime = 0.0f;	// time between current frame and last frame
		float lastFrame = 0.0f;
	};
}