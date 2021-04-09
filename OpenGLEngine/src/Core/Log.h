#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

namespace OGLE {

	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static Ref<spdlog::logger> s_Logger;
	};

}

#define OG_TRACE(...)    ::OGLE::Log::GetLogger()->trace(__VA_ARGS__)
#define OG_INFO(...)     ::OGLE::Log::GetLogger()->info(__VA_ARGS__)
#define OG_WARN(...)     ::OGLE::Log::GetLogger()->warn(__VA_ARGS__)
#define OG_ERROR(...)    ::OGLE::Log::GetLogger()->error(__VA_ARGS__)
#define OG_CRITICAL(...) ::OGLE::Log::GetLogger()->critical(__VA_ARGS__)