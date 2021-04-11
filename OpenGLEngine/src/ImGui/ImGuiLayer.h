#pragma once
#include "Core/Layer.h"

namespace OGLE
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer() : Layer("ImGui") {};
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(float ts) override;

		void Begin();
		void End();
	};
}