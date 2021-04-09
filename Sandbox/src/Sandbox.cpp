#include "OpenGLEngine.h"
#include "Core/EntryPoint.h"

#include "GameLayer.h"

namespace SANDBOX
{
	class Sandbox : public Application
	{
	public:
		Sandbox() : Application()
		{
			PushLayer(new GameLayer());
		}

		~Sandbox()
		{
		}
	};
}

namespace OGLE
{
	Application* CreateApplication()
	{
		return new SANDBOX::Sandbox();
	}
}