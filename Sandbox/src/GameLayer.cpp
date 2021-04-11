#include "GameLayer.h"
#include <imgui/imgui.h>

namespace SANDBOX
{
	GameLayer::GameLayer()
		: Layer("EditorLayer")
	{
		m_ActiveScene = CreateScope<Scene>();
	}

	void GameLayer::OnAttach()
	{
		
	}

	void GameLayer::OnDetach()
	{
	}

	void GameLayer::OnUpdate(float ts)
	{
		m_ActiveCamera.OnUpdate(ts);


		// render
		m_ActiveScene->OnUpdate(ts, m_ActiveCamera);
	}

	void GameLayer::OnImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}
}
