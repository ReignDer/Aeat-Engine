{
    files = {
        [[bin-int\debug-windows-x64\Sandbox\Sandbox\windows\x64\debug\Sandbox\src\SandBoxApp.cpp.obj]]
    },
    values = {
        [[C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.38.33130\bin\HostX64\x64\link.exe]],
        {
            "-nologo",
            "-dynamicbase",
            "-nxcompat",
            "-machine:x64",
            [[-libpath:bin\debug-windows-x64\Aeat]],
            "-debug",
            [[-pdb:bin\debug-windows-x64\Sandbox\Sandbox.pdb]],
            "Aeat.lib"
        }
    }
}