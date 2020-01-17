workspace "OpenGLEngine"
    architecture "x86_64"
    configurations { "Debug", "Release" }
    startproject "OpenGLEngine"

    flags {
		"MultiProcessorCompile"
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
    include "vendor/glfw"
    include "vendor/Glad"

group ""

project "OpenGLEngine"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader ("pch.h")

    IncludeDir = {}
    IncludeDir["GLFW"] = "vendor/glfw/include"
    IncludeDir["Glad"] = "vendor/Glad/include"

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLFW}/../deps",
        "%{IncludeDir.Glad}"
    }
    filter "system:linux"
        staticruntime "On"

        links {
            "GLFW",
            "Glad",
            "GL",
            "pthread",
            "Xrandr",
            "Xi",
            "dl",
            "X11"
        }
    
    filter "system:windows"
        systemversion "latest"
        staticruntime "On"

        pchsource ("src/pch.cpp")

        links {
            "GLFW",
            "Glad"
        }

    filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"