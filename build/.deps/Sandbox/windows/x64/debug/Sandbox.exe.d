{
    files = {
        [[bin-int\Debug-x64\Sandbox\Sandbox\windows\x64\debug\Sandbox\src\SandBoxApp.cpp.obj]],
        [[Aeat\vendor\Glad\bin\Debug-x64\Glad\Glad.lib]],
        [[Aeat\vendor\GLFW_new\bin\Debug-x64\GLFW\GLFW.lib]]
    },
    values = {
        [[C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.38.33130\bin\HostX64\x64\link.exe]],
        {
            "-nologo",
            "-dynamicbase",
            "-nxcompat",
            "-machine:x64",
            [[-libpath:bin\Debug-x64\Aeat]],
            [[-libpath:Aeat\vendor\GLFW_new\bin\Debug-x64\GLFW]],
            [[-libpath:Aeat\vendor\Glad\bin\Debug-x64\Glad]],
            "-debug",
            [[-pdb:bin\Debug-x64\Sandbox\Sandbox.pdb]],
            "Aeat.lib",
            "GLFW.lib",
            "Glad.lib"
        }
    }
}