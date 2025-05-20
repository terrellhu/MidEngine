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
IncludeDir["Glad"] = "MidEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "MidEngine/vendor/imgui"

include "MidEngine/vendor/GLFW"
include "MidEngine/vendor/Glad"
include "MidEngine/vendor/imgui"

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
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links 
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"

        defines
        {
            "ME_PLATFORM_WINDOWS",
            "ME_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ('mkdir "..\\bin\\' .. outputdir .. '\\Sandbox"'),
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "ME_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "ME_RELEASE"
        runtime "Release"
        symbols "On"

    filter "configurations:Dist"
        defines "ME_DIST"
        runtime "Release"
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
        staticruntime "Off"
        systemversion "latest"

        defines
        {
            "ME_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "ME_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "ME_RELEASE"
        runtime "Release"
        symbols "On"

    filter "configurations:Dist"
        defines "ME_DIST"
        runtime "Release"
        symbols "On"

    filter { "system:windows" }
        buildoptions { "/utf-8" }