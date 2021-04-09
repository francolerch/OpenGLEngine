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

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

	public:
		static Scope<SceneData> s_SceneData;
	};
}