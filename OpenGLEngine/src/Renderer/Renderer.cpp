#include "pch.h"
#include "Renderer.h"

namespace OGLE {
	Scope<Renderer::SceneData> Renderer::s_SceneData = CreateScope<Renderer::SceneData>();

	void Renderer::Init()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
	}

	void Renderer::Shutdown()
	{
	}
	
	void Renderer::BeginScene(const PerspectiveCamera& camera)
	{
		Renderer::s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
		Renderer::s_SceneData->ViewMatrix = camera.GetViewMatrix();
		Renderer::s_SceneData->ProjectionMatrix = camera.GetProjectionMatrix();

	}

	void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vao, const glm::mat4& transform)
	{
		shader->Bind();
		shader->SetMat4("u_ViewProjection", Renderer::s_SceneData->ViewProjectionMatrix);
		shader->SetMat4("u_Transform", transform);

		vao->Bind();
		unsigned int count = vao->GetIndexBuffer().GetSize() / sizeof(unsigned int) ;
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Renderer::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

}