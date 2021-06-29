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
		Model m_Model;
		Texture tex;
	};
}