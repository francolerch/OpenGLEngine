#include "pch.h"
#include "Entities/PerspectiveCamera.h"
#include "Core/Input/Input.h"
#include "Renderer/Renderer.h"

namespace OGLE {
	PerspectiveCamera::PerspectiveCamera() :
		Entity(glm::vec3(0.0f, 0.0f, 4.0f)),
		m_CameraFront(glm::vec3(0.0f, 0.0f, -1.0f)),
		m_CameraUp(glm::vec3(0.0f, 1.0f, 0.0f))
	{
		
	}

	PerspectiveCamera::~PerspectiveCamera()
	{
	}

	void PerspectiveCamera::OnUpdate(float dt)
	{
		Renderer::BeginScene(*this);

		float cameraSpeed = 2.5 * dt;
		if (Input::IsKeyPressed(OGLE_KEY_W))
			m_Position += cameraSpeed * m_CameraFront;
		if (Input::IsKeyPressed(OGLE_KEY_S))
			m_Position -= cameraSpeed * m_CameraFront;
		if (Input::IsKeyPressed(OGLE_KEY_A))
			m_Position -= glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * cameraSpeed;
		if (Input::IsKeyPressed(OGLE_KEY_D))
			m_Position += glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * cameraSpeed;
		if (Input::IsKeyPressed(OGLE_KEY_SPACE))
			m_Position += m_CameraUp * cameraSpeed;
		if (Input::IsKeyPressed(OGLE_KEY_LEFT_SHIFT))
			m_Position -= m_CameraUp * cameraSpeed;

		// MOVE THIS TO ANOTHER CLASS
		/*if (Input::IsKeyPressed(OGLE_KEY_F2)) 
		{
			auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow());
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}*/

		
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

	glm::mat4 PerspectiveCamera::GetViewProjectionMatrix() const
	{
		glm::mat4 proj = glm::perspective(glm::radians(60.f), 800.f / 600.f, 0.1f, 100.0f);
		return proj * glm::lookAt(GetPos(), GetCameraFront() + GetPos(), GetCameraUp());
	}
}