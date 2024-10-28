target("Glad")
	set_kind("static")
	set_languages("clatest")
	set_runtimes("MT")

	set_targetdir ("bin/" .. outputdir .. "/Glad")
	set_objectdir ("bin-int/" .. outputdir .. "/Glad")

	add_headerfiles(
		"include/glad/glad.h",
		"include/KHR/khrplatform.h"
	)

	add_files(
		"src/glad.c"

	)

	add_includedirs("include")

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