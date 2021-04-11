#include "GameLayer.h"
#include <imgui/imgui.h>

namespace SANDBOX
{
	GameLayer::GameLayer()
		: Layer("EditorLayer")
	{
		m_Model = CreateScope<Model>("res/models/me/untitled.obj");
	}

	void GameLayer::OnAttach()
	{
		
	}

	void GameLayer::OnDetach()
	{
	}

	void GameLayer::OnUpdate(float ts)
	{
		m_Model->Draw();
	}

	void GameLayer::OnImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}
}
