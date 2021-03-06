#pragma once

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Window.h"
#include "LayerStack.h"
#include "ImGui/ImGuiLayer.h"

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
		inline Window* GetWindow() { return m_Window.get(); }
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }

	private:
		static Application* s_Instance;

		Scope<Window> m_Window;
		//Scope<Renderer> m_Renderer;
		const float WIDTH = 1280.f;
		const float HEIGHT = 720.f;
		float deltaTime = 0.0f;	// time between current frame and last frame
		float lastFrame = 0.0f;
		class LayerStack m_LayerStack;
		Scope<ImGuiLayer> m_ImGuiLayer;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}