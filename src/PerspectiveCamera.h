#pragma once
#include "glm/glm.hpp"

namespace OGLE {
	class PerspectiveCamera
	{
	public:
		PerspectiveCamera();
		~PerspectiveCamera();

		void OnUpdate(float dt);
		inline const glm::vec3& GetCameraPos() const { return m_CameraPos; };
		inline const glm::vec3& GetCameraFront() const { return m_CameraFront; };
		inline const glm::vec3& GetCameraUp() const { return m_CameraUp; };

	private:
		glm::vec3 m_CameraPos;
		glm::vec3 m_CameraFront;
		glm::vec3 m_CameraUp;
		
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