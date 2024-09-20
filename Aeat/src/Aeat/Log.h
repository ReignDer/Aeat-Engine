#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Core.h"

namespace Aeat {
	class AEAT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define AE_CORE_TRACE(...)  ::Aeat::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AE_CORE_INFO(...)   ::Aeat::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AE_CORE_WARN(...)   ::Aeat::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AE_CORE_ERROR(...)  ::Aeat::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AE_CORE_FATAL(...)  ::Aeat::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define AE_TRACE(...)		::Aeat::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AE_INFO(...)		::Aeat::Log::GetClientLogger()->info(__VA_ARGS__)
#define AE_WARN(...)		::Aeat::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AE_ERROR(...)		::Aeat::Log::GetClientLogger()->error(__VA_ARGS__)
#define AE_FATAL(...)		::Aeat::Log::GetClientLogger()->fatal(__VA_ARGS__)
