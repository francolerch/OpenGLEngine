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

	private:
	
	};
}