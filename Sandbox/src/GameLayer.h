#pragma once
#include "OpenGLEngine.h"

using namespace OGLE;

namespace SANDBOX
{
	class GameLayer 
	{
	public:
		GameLayer();
		~GameLayer() = default;

		void OnAttach();
		void OnDetach();
		void OnUpdate(float ts);

	private:
	
	};
}