#pragma once
#include "OpenGLEngine.h"

using namespace OGLE;

namespace SANDBOX
{
	class GameLayer : public Layer
	{
	public:
		GameLayer();
		~GameLayer() = default;

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate(float ts) override;
		void OnImGuiRender() override;

	private:
		Ref<Scene> m_ActiveScene;
		Ref<Entity> m_ActiveCamera;
		Ref<FrameBuffer> m_FrameBuffer;
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
		Entity m_SelectionContext;

		std::filesystem::path m_CurrentDirectory = "assets";
		Ref<Texture> m_DirectoryIcon;
		Ref<Texture> m_FileIcon;

	};
}