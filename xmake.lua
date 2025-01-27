set_project("Aeat")
add_rules("plugin.vsxmake.autoupdate")
set_arch(os.arch())
add_rules("mode.debug","mode.release")
set_defaultmode("debug")

outputdir = ""
if is_mode("debug") then
	outputdir = "Debug-$(arch)"
elseif is_mode("release") then
	outputdir = "Release-$(arch)"
end

includes("Aeat/vendor/GLFW_new")
includes("Aeat/vendor/Glad")
includes("Aeat/vendor/imgui")


target("Aeat")
	set_kind("static")
	set_languages("c++17")
	set_runtimes("MT")

	set_targetdir("bin/".. outputdir .. "/Aeat")
	set_objectdir("bin-int/".. outputdir .. "/Aeat")

	set_pcxxheader("Aeat/src/aepch.h")
	add_headerfiles("Aeat/src/**.h", "Aeat/vendor/glm/glm/**.hpp")
	add_files("Aeat/src/**.cpp")
	add_extrafiles("Aeat/vendor/**.inl")
	
	add_defines("_CRT_SECURE_NO_WARNINGS")

	add_includedirs("Aeat/vendor/spdlog/include", "Aeat/src", 
		"Aeat/vendor/GLFW_new/include","Aeat/vendor/Glad/include",
		"Aeat/vendor/imgui", "Aeat/vendor/glm")

	add_deps("GLFW", "Glad", "ImGui")
	add_links(
		"GLFW", "Glad","ImGui",
		"opengl32.lib", "dwmapi.lib",
		"user32.lib", "gdi32.lib","shell32.lib"	
	)

	if is_os("windows") then
		set_languages("c++17")
		add_defines("WINVER=0x0A00")
		add_defines("_WIN32_WINNT=0x0A00") 
		add_defines("AE_PLATFORM_WINDOWS","AE_BUILD_DLL")
		--add_defines("GLFW_INCLUDE_NONE")
	end

	-- after_build(function (target) 
	-- 	local outputdir = ""
	-- 	if is_mode("debug") then
	-- 		outputdir = "Debug-$(arch)"
	-- 	elseif is_mode("release") then
	-- 		outputdir = "Release-$(arch)"
	-- 	end
	-- 	print("hello")
    --     os.cp("bin/" .. outputdir.."/Aeat/Aeat.dll", path.join("bin/" .. outputdir.. "/Sandbox", path.basename("bin/" .. outputdir.."/Aeat/Aeat.dll") .. ".dll"))  -- Copy the built target to the destination
	-- end)

	if is_mode("debug") then
		set_runtimes("MTd")
		add_defines("AE_DEBUG")
		set_symbols("debug")
	elseif is_mode("release") then 
		set_runtimes("MT")
		add_defines("AE_RELEASE")
		set_optimize("fast")
	end


target("Sandbox")
	set_kind("binary")
	set_languages("c++17")
	set_runtimes("MT")

	set_targetdir("bin/".. outputdir .. "/Sandbox")
	set_objectdir("bin-int/".. outputdir .. "/Sandbox")

	add_headerfiles("Sandbox/src/**.h")
	add_files("Sandbox/src/**.cpp")

	
	add_includedirs("Aeat/vendor/spdlog/include", "Aeat/src", "Aeat/vendor/glm")
	add_deps("Aeat")
	add_links("Aeat")
	add_linkdirs("bin/"..outputdir.."/Aeat")



	if is_os("windows") then
		if is_mode("debug") then
			set_runtimes("MTd")
		elseif is_mode("release") then
			set_runtimes("MT")
		end
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
