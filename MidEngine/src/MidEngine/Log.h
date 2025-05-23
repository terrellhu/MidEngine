#pragma once

#pragma warning(push)
#pragma warning(disable: 4251)

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "LogFormatter.h"

namespace ME {
	class ME_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};
}

#define ME_CORE_CRITICAL(...) ::ME::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define ME_CORE_ERROR(...) ::ME::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ME_CORE_WARN(...) ::ME::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ME_CORE_INFO(...) ::ME::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ME_CORE_TRACE(...) ::ME::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define ME_CRITICAL(...) ::ME::Log::GetClientLogger()->critical(__VA_ARGS__)
#define ME_ERROR(...) ::ME::Log::GetClientLogger()->error(__VA_ARGS__)
#define ME_WARN(...) ::ME::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ME_INFO(...) ::ME::Log::GetClientLogger()->info(__VA_ARGS__)
#define ME_TRACE(...) ::ME::Log::GetClientLogger()->trace(__VA_ARGS__)