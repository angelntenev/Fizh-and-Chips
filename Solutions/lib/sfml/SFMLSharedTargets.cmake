# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.6)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.20)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget SFML::System SFML::Main SFML::Window OpenGL SFML::Network SFML::Graphics Freetype OpenAL VORBIS FLAC SFML::Audio)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target SFML::System
add_library(SFML::System SHARED IMPORTED)

set_target_properties(SFML::System PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_17"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/include"
)

# Create imported target SFML::Main
add_library(SFML::Main STATIC IMPORTED)

set_target_properties(SFML::Main PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_17"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/include"
)

# Create imported target SFML::Window
add_library(SFML::Window SHARED IMPORTED)

set_target_properties(SFML::Window PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_17"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/include"
  INTERFACE_LINK_LIBRARIES "SFML::System"
)

# Create imported target OpenGL
add_library(OpenGL INTERFACE IMPORTED)

set_target_properties(OpenGL PROPERTIES
  INTERFACE_LINK_LIBRARIES "opengl32"
)

# Create imported target SFML::Network
add_library(SFML::Network SHARED IMPORTED)

set_target_properties(SFML::Network PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_17"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/include"
  INTERFACE_LINK_LIBRARIES "SFML::System"
)

# Create imported target SFML::Graphics
add_library(SFML::Graphics SHARED IMPORTED)

set_target_properties(SFML::Graphics PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_17"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/include"
  INTERFACE_LINK_LIBRARIES "SFML::Window"
)

# Create imported target Freetype
add_library(Freetype INTERFACE IMPORTED)

set_target_properties(Freetype PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/headers/freetype2"
  INTERFACE_LINK_LIBRARIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/libs-msvc-universal/x64/freetype.lib"
)

# Create imported target OpenAL
add_library(OpenAL INTERFACE IMPORTED)

set_target_properties(OpenAL PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/headers/AL"
  INTERFACE_LINK_LIBRARIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/libs-msvc-universal/x64/openal32.lib"
)

# Create imported target VORBIS
add_library(VORBIS INTERFACE IMPORTED)

set_target_properties(VORBIS PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "OV_EXCLUDE_STATIC_CALLBACKS"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/headers;C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/headers"
  INTERFACE_LINK_LIBRARIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/libs-msvc-universal/x64/vorbisenc.lib;C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/libs-msvc-universal/x64/vorbisfile.lib;C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/libs-msvc-universal/x64/vorbis.lib;C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/libs-msvc-universal/x64/ogg.lib"
)

# Create imported target FLAC
add_library(FLAC INTERFACE IMPORTED)

set_target_properties(FLAC PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "FLAC__NO_DLL"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/headers"
  INTERFACE_LINK_LIBRARIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/extlibs/libs-msvc-universal/x64/flac.lib"
)

# Create imported target SFML::Audio
add_library(SFML::Audio SHARED IMPORTED)

set_target_properties(SFML::Audio PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_17"
  INTERFACE_INCLUDE_DIRECTORIES "C:/Users/carlo/source/repos/Fizh-and-Chips/Cmake_stuff/lib/sfml/include"
  INTERFACE_LINK_LIBRARIES "SFML::System"
)

# Import target "SFML::System" for configuration "Debug"
set_property(TARGET SFML::System APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SFML::System PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Debug/sfml-system-d.lib"
  IMPORTED_LOCATION_DEBUG "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/Debug/sfml-system-d-3.dll"
  )

# Import target "SFML::Main" for configuration "Debug"
set_property(TARGET SFML::Main APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SFML::Main PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Debug/sfml-main-d.lib"
  )

# Import target "SFML::Window" for configuration "Debug"
set_property(TARGET SFML::Window APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SFML::Window PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Debug/sfml-window-d.lib"
  IMPORTED_LOCATION_DEBUG "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/Debug/sfml-window-d-3.dll"
  )

# Import target "SFML::Network" for configuration "Debug"
set_property(TARGET SFML::Network APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SFML::Network PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Debug/sfml-network-d.lib"
  IMPORTED_LOCATION_DEBUG "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/Debug/sfml-network-d-3.dll"
  )

# Import target "SFML::Graphics" for configuration "Debug"
set_property(TARGET SFML::Graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SFML::Graphics PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Debug/sfml-graphics-d.lib"
  IMPORTED_LOCATION_DEBUG "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/Debug/sfml-graphics-d-3.dll"
  )

# Import target "SFML::Audio" for configuration "Debug"
set_property(TARGET SFML::Audio APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SFML::Audio PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Debug/sfml-audio-d.lib"
  IMPORTED_LOCATION_DEBUG "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/Debug/sfml-audio-d-3.dll"
  )

# Import target "SFML::System" for configuration "Release"
set_property(TARGET SFML::System APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SFML::System PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Release/sfml-system.lib"
  IMPORTED_LOCATION_RELEASE "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/Release/sfml-system-3.dll"
  )

# Import target "SFML::Main" for configuration "Release"
set_property(TARGET SFML::Main APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SFML::Main PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Release/sfml-main.lib"
  )

# Import target "SFML::Window" for configuration "Release"
set_property(TARGET SFML::Window APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SFML::Window PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Release/sfml-window.lib"
  IMPORTED_LOCATION_RELEASE "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/Release/sfml-window-3.dll"
  )

# Import target "SFML::Network" for configuration "Release"
set_property(TARGET SFML::Network APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SFML::Network PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Release/sfml-network.lib"
  IMPORTED_LOCATION_RELEASE "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/Release/sfml-network-3.dll"
  )

# Import target "SFML::Graphics" for configuration "Release"
set_property(TARGET SFML::Graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SFML::Graphics PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Release/sfml-graphics.lib"
  IMPORTED_LOCATION_RELEASE "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/Release/sfml-graphics-3.dll"
  )

# Import target "SFML::Audio" for configuration "Release"
set_property(TARGET SFML::Audio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SFML::Audio PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/Release/sfml-audio.lib"
  IMPORTED_LOCATION_RELEASE "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/Release/sfml-audio-3.dll"
  )

# Import target "SFML::System" for configuration "MinSizeRel"
set_property(TARGET SFML::System APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(SFML::System PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/MinSizeRel/sfml-system.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/MinSizeRel/sfml-system-3.dll"
  )

# Import target "SFML::Main" for configuration "MinSizeRel"
set_property(TARGET SFML::Main APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(SFML::Main PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/MinSizeRel/sfml-main.lib"
  )

# Import target "SFML::Window" for configuration "MinSizeRel"
set_property(TARGET SFML::Window APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(SFML::Window PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/MinSizeRel/sfml-window.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/MinSizeRel/sfml-window-3.dll"
  )

# Import target "SFML::Network" for configuration "MinSizeRel"
set_property(TARGET SFML::Network APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(SFML::Network PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/MinSizeRel/sfml-network.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/MinSizeRel/sfml-network-3.dll"
  )

# Import target "SFML::Graphics" for configuration "MinSizeRel"
set_property(TARGET SFML::Graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(SFML::Graphics PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/MinSizeRel/sfml-graphics.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/MinSizeRel/sfml-graphics-3.dll"
  )

# Import target "SFML::Audio" for configuration "MinSizeRel"
set_property(TARGET SFML::Audio APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(SFML::Audio PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/MinSizeRel/sfml-audio.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/MinSizeRel/sfml-audio-3.dll"
  )

# Import target "SFML::System" for configuration "RelWithDebInfo"
set_property(TARGET SFML::System APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SFML::System PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/RelWithDebInfo/sfml-system.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/RelWithDebInfo/sfml-system-3.dll"
  )

# Import target "SFML::Main" for configuration "RelWithDebInfo"
set_property(TARGET SFML::Main APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SFML::Main PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/RelWithDebInfo/sfml-main.lib"
  )

# Import target "SFML::Window" for configuration "RelWithDebInfo"
set_property(TARGET SFML::Window APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SFML::Window PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/RelWithDebInfo/sfml-window.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/RelWithDebInfo/sfml-window-3.dll"
  )

# Import target "SFML::Network" for configuration "RelWithDebInfo"
set_property(TARGET SFML::Network APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SFML::Network PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/RelWithDebInfo/sfml-network.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/RelWithDebInfo/sfml-network-3.dll"
  )

# Import target "SFML::Graphics" for configuration "RelWithDebInfo"
set_property(TARGET SFML::Graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SFML::Graphics PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/RelWithDebInfo/sfml-graphics.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/RelWithDebInfo/sfml-graphics-3.dll"
  )

# Import target "SFML::Audio" for configuration "RelWithDebInfo"
set_property(TARGET SFML::Audio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SFML::Audio PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/lib/sfml/lib/RelWithDebInfo/sfml-audio.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Users/carlo/source/repos/Fizh-and-Chips/Solutions/bin/RelWithDebInfo/sfml-audio-3.dll"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
