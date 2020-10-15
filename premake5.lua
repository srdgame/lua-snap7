-- A solution
workspace "lua-snap7"
	configurations { "Debug", "Release"}
	location "build"

project "snap7"
	kind "SharedLib"
	language "C++"
	location "build/lua-snap7"
	targetprefix ""
	targetdir "bin/%{cfg.buildcfg}"
	dependson { "snap7-static" }

	includedirs { 
		--"/usr/include/lua5.3",
		"/home/cch/mycode/skynet/3rd/lua/",
		".",
		"./snap7/release/Wrappers/c-cpp/",
	}
	files { 
		"./src/**.hpp",
		"./src/**.cpp",
		"./sol/**.hpp",
		"./snap7/release/Wrappers/c-cpp/**.h",
		"./snap7/release/Wrappers/c-cpp/**.cpp",
	}

	-- buildoptions { '-Wno-unknown-warning', '-Wno-unknown-warning-option', '-Wall', '-Wextra', '-Wpedantic', '-pedantic', '-pedantic-errors', '-Wno-noexcept-type', '-std=c++14', '-ftemplate-depth=1024' }
	buildoptions { '-Wpedantic', '-pedantic', '-pedantic-errors', '-Wno-noexcept-type', '-std=c++14', '-ftemplate-depth=2048' }

	--libdirs { "../../bin" }
	links { "pthread", "snap7-static" }
	--linkoptions { "" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"

project "snap7-static"
	kind "StaticLib"
	language "C++"
	location "build/snap7"
	targetdir "bin/%{cfg.buildcfg}"

	includedirs { 
		"./snap7/src/sys/",
		"./snap7/src/core/",
		"./snap7/src/lib/",
	}
	files { 
		"./snap7/src/**.h",
		"./snap7/src/**.cpp",
	}

	buildoptions { '-Wpedantic', '-pedantic', '-pedantic-errors', '-Wno-noexcept-type', '-std=c++14', "-fPIC" }

	--libdirs { "../../bin" }
	links { "pthread"}
	--linkoptions { "" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"


