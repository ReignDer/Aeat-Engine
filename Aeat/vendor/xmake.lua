target("GLFW")
	set_kind("static")
	set_languages("c++14")

	set_warnings("none")

	set_targetdir ("bin/" .. outputdir .. "/GLFW")
	set_objectdir ("bin-int/" .. outputdir .. "/GLFW")

	add_headerfiles(
		"include/GLFW/glfw3.h",
		"include/GLFW/glfw3native.h",
		"src/glfw_config.h",
		"src/internal.h",
		"src/platform.h",
		"src/mappings.h",
		"src/null_platform.h",
		"src/null_joystick.h"
	)

	add_files(
		"src/context.c",
		"src/init.c",
		"src/input.c",
		"src/monitor.c",

		"src/null_init.c",
		"src/null_joystick.c",
		"src/null_monitor.c",
		"src/null_window.c",

		"src/platform.c",
		"src/vulkan.c",
		"src/window.c",
		"src/egl_context.c",
		"src/osmesa_context.c"

	)

	if is_os("linux") then
		add_cxxflags("-fPIC", { force = true })
		
		add_files(
			"src/x11_init.c",
			"src/x11_monitor.c",
			"src/x11_window.c",
			"src/xkb_unicode.c",
			"src/posix_module.c",
			"src/posix_time.c",
			"src/posix_thread.c",
			"src/posix_module.c",
			"src/glx_context.c",
			"src/egl_context.c",
			"src/osmesa_context.c",
			"src/linux_joystick.c"
		)

		add_defines("_GLFW_X11")

	elseif is_os("macosx") then
		add_cxxflags("-fPIC", { force = true })

		add_files(
			"src/cocoa_init.m",
			"src/cocoa_monitor.m",
			"src/cocoa_window.m",
			"src/cocoa_joystick.m",
			"src/cocoa_time.c",
			"src/nsgl_context.m",
			"src/posix_thread.c",
			"src/posix_module.c",
			"src/osmesa_context.c",
			"src/egl_context.c"
		)

		add_defines("_GLFW_COCOA")

	elseif is_os("windows") then
		if is_mode("debug") then
			set_runtimes("MTd")
			set_symbols("debug")
		end

		if is_os("windows") and is_mode("asan") then
			set_runtimes("MTd")
			set_symbols("debug")
			add_cxxflags("-fsanitize=address")
			add_ldflags("-fsanitize=address") 
			flags { "NoRuntimeChecks", "NoIncrementalLink" }
			add_ldflags("/INCREMENTAL:NO")
		end

		if is_mode("release") then
			set_runtimes("MT")
			set_optimize("fastest")
		end
		add_headerfiles(
			"src/win32_time.h",
			"src/win32_thread.h"
		)

		add_files(
			"src/win32_init.c",
			"src/win32_joystick.c",
			"src/win32_module.c",
			"src/win32_monitor.c",
			"src/win32_time.c",
			"src/win32_thread.c",
			"src/win32_window.c",
			"src/wgl_context.c",
			"src/egl_context.c",
			"src/osmesa_context.c"
		)

		add_defines(
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		)
	end

	if is_mode("debug") then
		set_runtimes("MTd")
		set_symbols("debug")
	end

	if is_os("windows") and is_mode("asan") then
		set_runtimes("MTd")
		set_symbols("debug")
		add_cxxflags("-fsanitize=address")
		add_ldflags("-fsanitize=address") 
		flags { "NoRuntimeChecks", "NoIncrementalLink" }
		add_ldflags("/INCREMENTAL:NO")
	end

	if is_mode("release") then
		set_runtimes("MT")
		set_optimize("fastest")
	end
