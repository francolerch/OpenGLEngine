#pragma once
#include "pch.h"
#include <stdint.h>

namespace OGLE
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define OGLE_KEY_SPACE           ::OGLE::Key::Space
#define OGLE_KEY_APOSTROPHE      ::OGLE::Key::Apostrophe    /* ' */
#define OGLE_KEY_COMMA           ::OGLE::Key::Comma         /* , */
#define OGLE_KEY_MINUS           ::OGLE::Key::Minus         /* - */
#define OGLE_KEY_PERIOD          ::OGLE::Key::Period        /* . */
#define OGLE_KEY_SLASH           ::OGLE::Key::Slash         /* / */
#define OGLE_KEY_0               ::OGLE::Key::D0
#define OGLE_KEY_1               ::OGLE::Key::D1
#define OGLE_KEY_2               ::OGLE::Key::D2
#define OGLE_KEY_3               ::OGLE::Key::D3
#define OGLE_KEY_4               ::OGLE::Key::D4
#define OGLE_KEY_5               ::OGLE::Key::D5
#define OGLE_KEY_6               ::OGLE::Key::D6
#define OGLE_KEY_7               ::OGLE::Key::D7
#define OGLE_KEY_8               ::OGLE::Key::D8
#define OGLE_KEY_9               ::OGLE::Key::D9
#define OGLE_KEY_SEMICOLON       ::OGLE::Key::Semicolon     /* ; */
#define OGLE_KEY_EQUAL           ::OGLE::Key::Equal         /* = */
#define OGLE_KEY_A               ::OGLE::Key::A
#define OGLE_KEY_B               ::OGLE::Key::B
#define OGLE_KEY_C               ::OGLE::Key::C
#define OGLE_KEY_D               ::OGLE::Key::D
#define OGLE_KEY_E               ::OGLE::Key::E
#define OGLE_KEY_F               ::OGLE::Key::F
#define OGLE_KEY_G               ::OGLE::Key::G
#define OGLE_KEY_H               ::OGLE::Key::H
#define OGLE_KEY_I               ::OGLE::Key::I
#define OGLE_KEY_J               ::OGLE::Key::J
#define OGLE_KEY_K               ::OGLE::Key::K
#define OGLE_KEY_L               ::OGLE::Key::L
#define OGLE_KEY_M               ::OGLE::Key::M
#define OGLE_KEY_N               ::OGLE::Key::N
#define OGLE_KEY_O               ::OGLE::Key::O
#define OGLE_KEY_P               ::OGLE::Key::P
#define OGLE_KEY_Q               ::OGLE::Key::Q
#define OGLE_KEY_R               ::OGLE::Key::R
#define OGLE_KEY_S               ::OGLE::Key::S
#define OGLE_KEY_T               ::OGLE::Key::T
#define OGLE_KEY_U               ::OGLE::Key::U
#define OGLE_KEY_V               ::OGLE::Key::V
#define OGLE_KEY_W               ::OGLE::Key::W
#define OGLE_KEY_X               ::OGLE::Key::X
#define OGLE_KEY_Y               ::OGLE::Key::Y
#define OGLE_KEY_Z               ::OGLE::Key::Z
#define OGLE_KEY_LEFT_BRACKET    ::OGLE::Key::LeftBracket   /* [ */
#define OGLE_KEY_BACKSLASH       ::OGLE::Key::Backslash     /* \ */
#define OGLE_KEY_RIGHT_BRACKET   ::OGLE::Key::RightBracket  /* ] */
#define OGLE_KEY_GRAVE_ACCENT    ::OGLE::Key::GraveAccent   /* ` */
#define OGLE_KEY_WORLD_1         ::OGLE::Key::World1        /* non-US #1 */
#define OGLE_KEY_WORLD_2         ::OGLE::Key::World2        /* non-US #2 */

/* Function keys */
#define OGLE_KEY_ESCAPE          ::OGLE::Key::Escape
#define OGLE_KEY_ENTER           ::OGLE::Key::Enter
#define OGLE_KEY_TAB             ::OGLE::Key::Tab
#define OGLE_KEY_BACKSPACE       ::OGLE::Key::Backspace
#define OGLE_KEY_INSERT          ::OGLE::Key::Insert
#define OGLE_KEY_DELETE          ::OGLE::Key::Delete
#define OGLE_KEY_RIGHT           ::OGLE::Key::Right
#define OGLE_KEY_LEFT            ::OGLE::Key::Left
#define OGLE_KEY_DOWN            ::OGLE::Key::Down
#define OGLE_KEY_UP              ::OGLE::Key::Up
#define OGLE_KEY_PAGE_UP         ::OGLE::Key::PageUp
#define OGLE_KEY_PAGE_DOWN       ::OGLE::Key::PageDown
#define OGLE_KEY_HOME            ::OGLE::Key::Home
#define OGLE_KEY_END             ::OGLE::Key::End
#define OGLE_KEY_CAPS_LOCK       ::OGLE::Key::CapsLock
#define OGLE_KEY_SCROLL_LOCK     ::OGLE::Key::ScrollLock
#define OGLE_KEY_NUM_LOCK        ::OGLE::Key::NumLock
#define OGLE_KEY_PRINT_SCREEN    ::OGLE::Key::PrintScreen
#define OGLE_KEY_PAUSE           ::OGLE::Key::Pause
#define OGLE_KEY_F1              ::OGLE::Key::F1
#define OGLE_KEY_F2              ::OGLE::Key::F2
#define OGLE_KEY_F3              ::OGLE::Key::F3
#define OGLE_KEY_F4              ::OGLE::Key::F4
#define OGLE_KEY_F5              ::OGLE::Key::F5
#define OGLE_KEY_F6              ::OGLE::Key::F6
#define OGLE_KEY_F7              ::OGLE::Key::F7
#define OGLE_KEY_F8              ::OGLE::Key::F8
#define OGLE_KEY_F9              ::OGLE::Key::F9
#define OGLE_KEY_F10             ::OGLE::Key::F10
#define OGLE_KEY_F11             ::OGLE::Key::F11
#define OGLE_KEY_F12             ::OGLE::Key::F12
#define OGLE_KEY_F13             ::OGLE::Key::F13
#define OGLE_KEY_F14             ::OGLE::Key::F14
#define OGLE_KEY_F15             ::OGLE::Key::F15
#define OGLE_KEY_F16             ::OGLE::Key::F16
#define OGLE_KEY_F17             ::OGLE::Key::F17
#define OGLE_KEY_F18             ::OGLE::Key::F18
#define OGLE_KEY_F19             ::OGLE::Key::F19
#define OGLE_KEY_F20             ::OGLE::Key::F20
#define OGLE_KEY_F21             ::OGLE::Key::F21
#define OGLE_KEY_F22             ::OGLE::Key::F22
#define OGLE_KEY_F23             ::OGLE::Key::F23
#define OGLE_KEY_F24             ::OGLE::Key::F24
#define OGLE_KEY_F25             ::OGLE::Key::F25

/* Keypad */
#define OGLE_KEY_KP_0            ::OGLE::Key::KP0
#define OGLE_KEY_KP_1            ::OGLE::Key::KP1
#define OGLE_KEY_KP_2            ::OGLE::Key::KP2
#define OGLE_KEY_KP_3            ::OGLE::Key::KP3
#define OGLE_KEY_KP_4            ::OGLE::Key::KP4
#define OGLE_KEY_KP_5            ::OGLE::Key::KP5
#define OGLE_KEY_KP_6            ::OGLE::Key::KP6
#define OGLE_KEY_KP_7            ::OGLE::Key::KP7
#define OGLE_KEY_KP_8            ::OGLE::Key::KP8
#define OGLE_KEY_KP_9            ::OGLE::Key::KP9
#define OGLE_KEY_KP_DECIMAL      ::OGLE::Key::KPDecimal
#define OGLE_KEY_KP_DIVIDE       ::OGLE::Key::KPDivide
#define OGLE_KEY_KP_MULTIPLY     ::OGLE::Key::KPMultiply
#define OGLE_KEY_KP_SUBTRACT     ::OGLE::Key::KPSubtract
#define OGLE_KEY_KP_ADD          ::OGLE::Key::KPAdd
#define OGLE_KEY_KP_ENTER        ::OGLE::Key::KPEnter
#define OGLE_KEY_KP_EQUAL        ::OGLE::Key::KPEqual

#define OGLE_KEY_LEFT_SHIFT      ::OGLE::Key::LeftShift
#define OGLE_KEY_LEFT_CONTROL    ::OGLE::Key::LeftControl
#define OGLE_KEY_LEFT_ALT        ::OGLE::Key::LeftAlt
#define OGLE_KEY_LEFT_SUPER      ::OGLE::Key::LeftSuper
#define OGLE_KEY_RIGHT_SHIFT     ::OGLE::Key::RightShift
#define OGLE_KEY_RIGHT_CONTROL   ::OGLE::Key::RightControl
#define OGLE_KEY_RIGHT_ALT       ::OGLE::Key::RightAlt
#define OGLE_KEY_RIGHT_SUPER     ::OGLE::Key::RightSuper
#define OGLE_KEY_MENU            ::OGLE::Key::Menu
