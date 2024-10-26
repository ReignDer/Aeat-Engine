{
    files = {
        [[bin-int\Debug-x64\Aeat\Aeat\windows\x64\debug\Aeat\src\Aeat\Application.cpp.obj]],
        [[bin-int\Debug-x64\Aeat\Aeat\windows\x64\debug\Aeat\src\Aeat\ImGui\ImGuiLayer.cpp.obj]],
        [[bin-int\Debug-x64\Aeat\Aeat\windows\x64\debug\Aeat\src\Aeat\Layer.cpp.obj]],
        [[bin-int\Debug-x64\Aeat\Aeat\windows\x64\debug\Aeat\src\Aeat\LayerStack.cpp.obj]],
        [[bin-int\Debug-x64\Aeat\Aeat\windows\x64\debug\Aeat\src\Aeat\Log.cpp.obj]],
        [[bin-int\Debug-x64\Aeat\Aeat\windows\x64\debug\Aeat\src\aepch.cpp.obj]],
        [[bin-int\Debug-x64\Aeat\Aeat\windows\x64\debug\Aeat\src\Platform\OpenGL\ImGuiOpenGLRenderer.cpp.obj]],
        [[bin-int\Debug-x64\Aeat\Aeat\windows\x64\debug\Aeat\src\Platform\Windows\WindowsWindow.cpp.obj]],
        [[bin-int\Debug-x64\Aeat\Aeat\windows\x64\debug\gens\Aeat\src\cxx\aepch.h_v143.pch.obj]],
        [[Aeat\vendor\imgui\bin\Debug-x64\ImGui\ImGui.lib]],
        [[Aeat\vendor\Glad\bin\Debug-x64\Glad\Glad.lib]],
        [[Aeat\vendor\GLFW_new\bin\Debug-x64\GLFW\GLFW.lib]]
    },
    values = {
        [[C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.38.33130\bin\HostX64\x64\link.exe]],
        {
            "-nologo",
            "-machine:x64",
            [[-libpath:Aeat\vendor\GLFW_new\bin\Debug-x64\GLFW]],
            [[-libpath:Aeat\vendor\Glad\bin\Debug-x64\Glad]],
            [[-libpath:Aeat\vendor\imgui\bin\Debug-x64\ImGui]],
            "-debug",
            [[-pdb:bin\Debug-x64\Aeat\Aeat.pdb]],
            "opengl32.lib",
            "dwmapi.lib",
            "user32.lib",
            "gdi32.lib",
            "shell32.lib",
            "GLFW.lib",
            "Glad.lib",
            "ImGui.lib"
        }
    }
}