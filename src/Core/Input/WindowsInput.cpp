#include "pch.h"
#include "WindowsInput.h"

#include "Core/Application.h"
#include "glad/glad.h"

namespace OGLE {

	std::unique_ptr<Input> Input::s_Instance = std::make_unique<WindowsInput>();

	bool WindowsInput::IsKeyPressedImpl(KeyCode key)
	{
		auto window = Application::Get().GetWindow();
		auto state = window->GetKey(static_cast<int32_t>(key));
		return state == PRESS || state == REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(MouseCode button)
	{
		auto window = Application::Get().GetWindow();
		auto state = window->GetMouseButton(static_cast<int32_t>(button));
		return state == PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = Application::Get().GetWindow();
		return window->GetMousePos();
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}

}