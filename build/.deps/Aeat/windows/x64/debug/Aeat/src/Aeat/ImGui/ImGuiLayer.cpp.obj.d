{
    values = {
        [[C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.38.33130\bin\HostX64\x64\cl.exe]],
        {
            "-nologo",
            "-Zi",
            "-FS",
            [[-Fdbin\Debug-x64\Aeat\Aeat.pdb]],
            "-Od",
            "-std:c++17",
            "-MTd",
            [[-IAeat\vendor\spdlog\include]],
            [[-IAeat\src]],
            [[-IAeat\vendor\GLFW_new\include]],
            [[-IAeat\vendor\Glad\include]],
            [[-IAeat\vendor\imgui]],
            [[-IAeat\vendor\glm]],
            "-D_CRT_SECURE_NO_WARNINGS",
            "-DWINVER=0x0A00",
            "-D_WIN32_WINNT=0x0A00",
            "-DAE_PLATFORM_WINDOWS",
            "-DAE_BUILD_DLL",
            "-DAE_DEBUG",
            "/EHsc",
            [[-YuC:\dev\Aeat\build\.gens\Aeat\windows\x64\debug\Aeat\src\aepch.h]],
            [[-FIC:\dev\Aeat\build\.gens\Aeat\windows\x64\debug\Aeat\src\aepch.h]],
            [[-Fpbin-int\Debug-x64\Aeat\Aeat\windows\x64\debug\gens\Aeat\src\cxx\aepch.h_v143.pch]]
        }
    },
    files = {
        [[Aeat\src\Aeat\ImGui\ImGuiLayer.cpp]],
        [[bin-int\Debug-x64\Aeat\Aeat\windows\x64\debug\gens\Aeat\src\cxx\aepch.h_v143.pch]]
    },
    depfiles_cl_json = "{\
    \"Version\": \"1.2\",\
    \"Data\": {\
        \"Source\": \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\imgui\\\\imguilayer.cpp\",\
        \"ProvidedModule\": \"\",\
        \"PCH\": \"c:\\\\dev\\\\aeat\\\\bin-int\\\\debug-x64\\\\aeat\\\\aeat\\\\windows\\\\x64\\\\debug\\\\gens\\\\aeat\\\\src\\\\cxx\\\\aepch.h_v143.pch\",\
        \"Includes\": [\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\imgui\\\\imguilayer.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\vendor\\\\imgui\\\\backends\\\\imgui_impl_opengl3.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\vendor\\\\imgui\\\\imgui.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\vendor\\\\imgui\\\\imconfig.h\",\
            \"c:\\\\program files (x86)\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\assert.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\vendor\\\\imgui\\\\backends\\\\imgui_impl_glfw.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\layer.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\events\\\\event.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\application.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\events\\\\applicationevent.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\window.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\layerstack.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\input.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\events\\\\keyevent.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\events\\\\mouseevent.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\vendor\\\\glfw_new\\\\include\\\\glfw\\\\glfw3.h\",\
            \"c:\\\\program files (x86)\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\gl\\\\gl.h\"\
        ],\
        \"ImportedModules\": [],\
        \"ImportedHeaderUnits\": []\
    }\
}"
}