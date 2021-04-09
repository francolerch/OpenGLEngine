#pragma once
#include "Core/Core.h"

extern OGLE::Application* OGLE::CreateApplication();

int main(int argc, char** argv)
{
	OGLE::Log::Init();

	OGLE::Application* app = OGLE::CreateApplication();
	app->Run();
	delete app;

	return 0;
}