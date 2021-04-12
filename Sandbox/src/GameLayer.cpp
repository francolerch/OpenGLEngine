#include "GameLayer.h"
#include <imgui/imgui.h>
#include "Scene/Components.h"

namespace SANDBOX
{
	GameLayer::GameLayer()
		: Layer("EditorLayer")
	{
	}

	void GameLayer::OnAttach()
	{
		m_ActiveScene = CreateScope<Scene>();

		Entity m_ActiveCamera = m_ActiveScene->CreateEntity("Camera");
		m_ActiveCamera.AddComponent<CameraComponent>();
	}

	void GameLayer::OnDetach()
	{
	}

	void GameLayer::OnUpdate(float ts)
	{
		// updates

		// render Scene
		m_ActiveScene->OnUpdate(ts);
	}

	void GameLayer::OnImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}
}
