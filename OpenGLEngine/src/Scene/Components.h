#pragma once
#include "Core/Core.h"
#include "glm/glm.hpp"
#include <glm/gtx/quaternion.hpp>

#include "Entities/PerspectiveCamera.h"
#include "Core/Model.h"

namespace OGLE
{
    struct TagComponent
    {
        std::string m_Tag;

        TagComponent() = default;
        TagComponent(const TagComponent&) = default;
        TagComponent(const std::string& tag)
            : m_Tag(tag) {};

        operator std::string& () { return m_Tag; };
        operator const std::string& () const { return m_Tag; };
    };
    
    struct TransformComponent
    {
        glm::vec3 Translation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Rotation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Scale = { 1.0f, 1.0f, 1.0f };

        TransformComponent() = default;
        TransformComponent(const TransformComponent&) = default;
        TransformComponent(const glm::vec3& translation)
            : Translation(translation) {};

		glm::mat4 GetTransform() const
		{
			glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));

			return glm::translate(glm::mat4(1.0f), Translation)
				* rotation
				* glm::scale(glm::mat4(1.0f), Scale);
		}
    };

	struct CameraComponent
	{
		PerspectiveCamera m_Camera;

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;
		CameraComponent(const PerspectiveCamera& projection)
			: m_Camera(projection) {};

		operator PerspectiveCamera& () { return m_Camera; };
		operator const PerspectiveCamera& () const { return m_Camera; };
	};

	struct RenderComponent
	{
		Model m_Model;

		RenderComponent(const std::string& path)
			: m_Model(path) {};

		operator Model& () { return m_Model; };
		operator const Model& () const { return m_Model; };

	};

	struct DirectionalLightComponent
	{
		float m_Intensity = 1.f;
		glm::vec3 m_Color;

		DirectionalLightComponent(glm::vec3 color = glm::vec3(1.f), float intensity = 1.f) {};
	};
}