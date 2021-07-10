#pragma once
#include "Core/Core.h"
#include "Renderer/Shader.h"
#include "Renderer/VertexArray.h"
#include "Entities/PerspectiveCamera.h"

namespace OGLE {
	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();
		static void BeginScene(const PerspectiveCamera& camera);

		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vao, const glm::mat4& transform = glm::mat4(1.0f));
		static void SetClearColor(const glm::vec4& color);
		static void Clear();

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
			glm::mat4 ViewMatrix;
			glm::mat4 ProjectionMatrix;
		};

	public:
		static Scope<SceneData> s_SceneData;
	};
}