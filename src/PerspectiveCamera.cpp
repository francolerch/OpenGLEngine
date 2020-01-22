#include "pch.h"
#include "PerspectiveCamera.h"
#include "Input.h"
#include "Keycodes.h"
#include "Application.h"

namespace OGLE {
	PerspectiveCamera::PerspectiveCamera() :
		m_CameraPos(glm::vec3(0.0f, 0.0f, 4.0f)),
		m_CameraFront(glm::vec3(0.0f, 0.0f, -1.0f)),
		m_CameraUp(glm::vec3(0.0f, 1.0f, 0.0f))
	{
		
	}

	PerspectiveCamera::~PerspectiveCamera()
	{
	}

	void PerspectiveCamera::OnUpdate(float dt)
	{
		if (Input::IsKeyPressed(OGLE_KEY_ESCAPE))
		{
			auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow());
			glfwSetWindowShouldClose(window, true);
		}

		float cameraSpeed = 2.5 * dt;
		if (Input::IsKeyPressed(OGLE_KEY_W))
			m_CameraPos += cameraSpeed * m_CameraFront;
		if (Input::IsKeyPressed(OGLE_KEY_S))
			m_CameraPos -= cameraSpeed * m_CameraFront;
		if (Input::IsKeyPressed(OGLE_KEY_A))
			m_CameraPos -= glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * cameraSpeed;
		if (Input::IsKeyPressed(OGLE_KEY_D))
			m_CameraPos += glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * cameraSpeed;
		if (Input::IsKeyPressed(OGLE_KEY_SPACE))
			m_CameraPos += m_CameraUp * cameraSpeed;
		if (Input::IsKeyPressed(OGLE_KEY_LEFT_SHIFT))
			m_CameraPos -= m_CameraUp * cameraSpeed;

		// MOVE THIS TO ANOTHER CLASS
		if (Input::IsKeyPressed(OGLE_KEY_F2)) 
		{
			auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow());
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}

		
		auto mousePos = Input::GetMousePosition();
		if(firstMouse)
		{
			lastX = mousePos.first;
			lastY = mousePos.second;
			firstMouse = false;
		}
		float xpos = mousePos.first;
		float ypos = mousePos.second;
		float xoffset = xpos - mouseXpos;
		float yoffset =mouseYpos - ypos;
		mouseXpos = xpos;
		mouseYpos = ypos;

		float sensitivity = 0.1;
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw += xoffset;
		pitch += yoffset;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 direction;
		direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		direction.y = sin(glm::radians(pitch));
		direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		m_CameraFront = glm::normalize(direction);
	}
}