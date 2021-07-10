#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace OGLE {
	class PerspectiveCamera
	{
	public:
		PerspectiveCamera();
		~PerspectiveCamera();

		void OnUpdate(float dt);
		const glm::vec3& GetCameraFront() const { return m_CameraFront; };
		const glm::vec3& GetCameraUp() const { return m_CameraUp; };

		const glm::mat4& GetViewProjectionMatrix() const;
		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		glm::vec3 GetPos() const { return m_Position; };

	private:
		glm::vec3 m_CameraFront;
		glm::vec3 m_CameraUp;
		glm::vec3 m_Position;

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		
		bool firstMouse = true;
		float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
		float pitch = 0.0f;
		float lastX = 640.0f / 2.0;
		float lastY = 480.0 / 2.0;
		float fov = 60.0f;

		float mouseXpos = 0.;
		float mouseYpos = 0.;
	};
}