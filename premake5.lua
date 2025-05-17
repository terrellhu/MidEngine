workspace "MidEngine"
	architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

startproject "Sandbox"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "MidEngine/vendor/GLFW/include"

include "MidEngine/vendor/GLFW"

project "MidEngine"
    location "MidEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mepch.h"
    pchsource "%{prj.name}/src/mepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links 
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ME_PLATFORM_WINDOWS",
            "ME_BUILD_DLL"
        }

        postbuildcommands
        {
            ('mkdir "..\\bin\\' .. outputdir .. '\\Sandbox"'),
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "ME_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ME_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "ME_DIST"
        symbols "On"

    filter { "system:windows" }
        buildoptions { "/utf-8" }

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

     files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "MidEngine/vendor/spdlog/include",
        "MidEngine/src"
    }

    links
    {
        "MidEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ME_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "ME_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ME_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "ME_DIST"
        symbols "On"

    filter { "system:windows" }
        buildoptions { "/utf-8" }