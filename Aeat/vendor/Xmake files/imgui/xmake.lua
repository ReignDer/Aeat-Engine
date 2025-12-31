target("ImGui")
	set_kind("static")
	set_languages("cxx17")

	set_targetdir ("bin/" .. outputdir .. "/ImGui")
	set_objectdir ("bin-int/" .. outputdir .. "/ImGui")

	add_defines("IMGUI_API=__declspec(dllexport)")

	add_headerfiles(
        "imconfig.h",
		"imgui.h",
		"imgui_internal.h",
        "imstb_rectpack.h",
        "imstb_textedit.h",
        "imstb_truetype.h"


	)

	add_files(
		"imgui.cpp",
		"imgui_demo.cpp",
		"imgui_draw.cpp",
		"imgui_tables.cpp",
		"imgui_widgets.cpp"

	)

	if is_os("windows") then
		add_defines("WINVER=0x0A00")
		add_defines("_WIN32_WINNT=0x0A00") 
		
	end

	if is_mode("debug") then
		set_runtimes("MTd")
		set_symbols("debug")
	end

	if is_os("windows") and is_mode("asan") then
		set_runtimes("MTd")
		set_symbols("debug")
	end
	
	if is_mode("release") then
		set_runtimes("MT")
		set_optimize("fastest")
	end
