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

    --pchheader ("pch.h")
    --pchsource ("src/pch.cpp")

    IncludeDir = {}
    IncludeDir["GLFW"] = "vendor/glfw/include"
    IncludeDir["Glad"] = "vendor/Glad/include"
    IncludeDir["stb_image"] = "vendor/stb_image"
    IncludeDir["glm"] = "vendor/glm"
    IncludeDir["spdlog"] = "vendor/spdlog/include"

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.spdlog}"
    }
    filter "system:linux"
        staticruntime "On"

        defines {
            "OG_LINUX"
        }

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

        defines {
            "OG_WINDOWS"
        }

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