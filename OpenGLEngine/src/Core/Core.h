#pragma once
#include <memory>

#ifdef OG_LINUX
	#define OG_BREAK __builtin_trap()
#else
	#define OG_BREAK __debugbreak()
#endif
#ifdef DEBUG
	#define OG_ASSERT(x, ...) { if(!(x)) { OG_ERROR("Assertion Failed: {0}", __VA_ARGS__); OG_BREAK; } }
#else
	#define OG_ASSERT(x, ...)
#endif

namespace OGLE {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "Core/Log.h"