cmake_minimum_required (VERSION 3.16)

# Enable in cross-platform way multi-processor compilation
macro(EnableMultiProcessorCompilation TARGET_NAME)
    if(MSVC)
	    target_compile_options(${TARGET_NAME} PUBLIC /MP)
    endif(MSVC)
    #TODO: support other compilers
endmacro()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "graph-tool")

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
set(BUILD_FOLDER "${CMAKE_SOURCE_DIR}/build/binaries")

project ("graph-maker")

#add_compile_definitions(-DSFML_STATIC)

#set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CMAKE_SOURCE_DIR}/thirdparty/SFML/cmake")

add_subdirectory("thirdparty/SFML")
add_subdirectory("graph-tool")


