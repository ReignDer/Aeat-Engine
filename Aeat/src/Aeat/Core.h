#pragma once

#ifdef AE_PLATFORM_WINDOWS
	#ifdef AE_BUILD_DLL
		#define AEAT_API __declspec(dllexport)
	#else
		#define AEAT_API __declspec(dllimport)
	#endif
#else
	#error AEAT only supports Windows.
#endif

