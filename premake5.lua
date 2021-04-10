workspace "OpenGLEngine"
    architecture "x86_64"
    configurations { "Debug", "Release" }
    startproject "Sandbox"

    flags {
		"MultiProcessorCompile"
    }
    
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    group "Dependencies"
        include "OpenGLEngine/vendor/glfw"
        include "OpenGLEngine/vendor/Glad"
        include "OpenGLEngine/vendor/entt"

    group ""

    project "OpenGLEngine"
        location "OpenGLEngine"
        kind "StaticLib"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        pchheader ("pch.h")
        pchsource ("%{prj.name}/src/pch.cpp")

        IncludeDir = {}
        IncludeDir["GLFW"] = "OpenGlEngine/vendor/glfw/include"
        IncludeDir["Glad"] = "OpenGlEngine/vendor/Glad/include"
        IncludeDir["glm"] = "OpenGlEngine/vendor/glm"
        IncludeDir["spdlog"] = "OpenGlEngine/vendor/spdlog/include"
        IncludeDir["assimp"] = "OpenGlEngine/vendor/assimp/include"
        IncludeDir["stb_image"] = "OpenGlEngine/vendor/stb_image"
        IncludeDir["entt"] = "OpenGlEngine/vendor/entt/single_include"


        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs {
            "%{prj.name}/src",
            "%{IncludeDir.GLFW}",
            "%{IncludeDir.Glad}",
            "%{IncludeDir.glm}",
            "%{IncludeDir.spdlog}",
            "%{IncludeDir.assimp}",
            "%{IncludeDir.stb_image}",
            "%{IncludeDir.entt}"
        }

        libdirs {
            "%{prj.name}vendor/assimp/lib"
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
                "X11",
                "assimp"
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

    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs {
            "%{prj.name}/src",
            "OpenGLEngine/src",
            "%{IncludeDir.spdlog}",
            "%{IncludeDir.glm}",
            "%{IncludeDir.Glad}",
            "%{IncludeDir.GLFW}",
            "%{IncludeDir.entt}"
        }

        links {
            "OpenGLEngine"
        }

        filter "system:windows"
            systemversion "latest"
        
        filter "configurations:Debug"
            defines "OGLE_DEBUG"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            defines "OGLE_RELEASE"
            runtime "Release"
            optimize "on"

        filter "configurations:Dist"
            defines "OGLE_DIST"
            runtime "Release"
            optimize "on"