{
    values = {
        [[C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.38.33130\bin\HostX64\x64\cl.exe]],
        {
            "-nologo",
            "-Zi",
            "-FS",
            [[-Fdbin\debug-windows-x64\Aeat\compile.Aeat.pdb]],
            "-Od",
            "-std:c++14",
            [[-IAeat\vendor\spdlog\include]],
            "-DWINVER=0x0A00",
            "-D_WIN32_WINNT=0x0A00",
            "-DAE_PLATFORM_WINDOWS",
            "-DAE_BUILD_DLL",
            "-DAE_DEBUG",
            "/EHsc"
        }
    },
    files = {
        [[Aeat\src\Aeat\Application.cpp]]
    },
    depfiles_cl_json = "{\
    \"Version\": \"1.2\",\
    \"Data\": {\
        \"Source\": \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\application.cpp\",\
        \"ProvidedModule\": \"\",\
        \"Includes\": [\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\application.h\",\
            \"c:\\\\dev\\\\aeat\\\\aeat\\\\src\\\\aeat\\\\core.h\"\
        ],\
        \"ImportedModules\": [],\
        \"ImportedHeaderUnits\": []\
    }\
}"
}