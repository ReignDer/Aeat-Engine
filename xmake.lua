set_project("Aeat")
set_arch(os.arch())
add_rules("mode.debug","mode.release")

outputdir = "$(mode)-$(os)-$(arch)"

target("Aeat")
	set_kind("shared")
	set_languages("c++14")

	set_targetdir("bin/".. outputdir .. "/Aeat")
	set_objectdir("bin-int/".. outputdir .. "/Aeat")

	add_headerfiles("Aeat/src/**.h")
	add_files("Aeat/src/**.cpp")

	add_includedirs("Aeat/vendor/spdlog/include")

	if is_os("windows") then
		set_languages("c++14")
		set_runtimes("c++_static")
		add_defines("WINVER=0x0A00")
		add_defines("_WIN32_WINNT=0x0A00") 
		add_defines("AE_PLATFORM_WINDOWS","AE_BUILD_DLL","_WINDLL")
	end

	after_build(function (target) 
		os.cp("bin/" ..outputdir.. "/Aeat/Aeat.dll","bin/".. outputdir.. "/Sandbox")
	end)

	if is_mode("debug") then
		add_defines("AE_DEBUG")
		set_symbols("debug")
	elseif is_mode("release") then 
		add_defines("AE_RELEASE")
		set_optimize("fast")
	end


target("Sandbox")
	set_kind("binary")
	set_languages("c++14")

	set_targetdir("bin/".. outputdir .. "/Sandbox")
	set_objectdir("bin-int/".. outputdir .. "/Sandbox")

	add_headerfiles("Sandbox/src/**.h")
	add_files("Sandbox/src/**.cpp")

	add_includedirs("Aeat/vendor/spdlog/include", "Aeat/src")
	add_linkdirs("bin/".. outputdir .."/Sandbox")

	add_links("Aeat")

	if is_os("windows") then
		set_runtimes("c++_static")
		add_defines("WINVER=0x0A00")
		add_defines("_WIN32_WINNT=0x0A00") 
		add_defines("AE_PLATFORM_WINDOWS")
	end

	if is_mode("debug") then
		add_defines("AE_DEBUG")
		set_symbols("debug")
	elseif is_mode("release") then 
		add_defines("AE_RELEASE")
		set_optimize("fast")
	end
