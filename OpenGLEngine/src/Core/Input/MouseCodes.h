#pragma once
#include "pch.h"
#include <stdint.h>

namespace OGLE
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define OGLE_MOUSE_BUTTON_0      ::OGLE::Mouse::Button0
#define OGLE_MOUSE_BUTTON_1      ::OGLE::Mouse::Button1
#define OGLE_MOUSE_BUTTON_2      ::OGLE::Mouse::Button2
#define OGLE_MOUSE_BUTTON_3      ::OGLE::Mouse::Button3
#define OGLE_MOUSE_BUTTON_4      ::OGLE::Mouse::Button4
#define OGLE_MOUSE_BUTTON_5      ::OGLE::Mouse::Button5
#define OGLE_MOUSE_BUTTON_6      ::OGLE::Mouse::Button6
#define OGLE_MOUSE_BUTTON_7      ::OGLE::Mouse::Button7
#define OGLE_MOUSE_BUTTON_LAST   ::OGLE::Mouse::ButtonLast
#define OGLE_MOUSE_BUTTON_LEFT   ::OGLE::Mouse::ButtonLeft
#define OGLE_MOUSE_BUTTON_RIGHT  ::OGLE::Mouse::ButtonRight
#define OGLE_MOUSE_BUTTON_MIDDLE ::OGLE::Mouse::ButtonMiddle
