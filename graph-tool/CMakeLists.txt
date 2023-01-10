cmake_minimum_required (VERSION 3.16)


project ("graph-tool")

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS 
	Athena.def
	"*.h" 
	"*.cpp" 
)

add_executable(graph-tool ${SRC_FILES})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SRC_FILES} )
EnableMultiProcessorCompilation(graph-tool)

set_property(TARGET graph-tool PROPERTY CXX_STANDARD 17)

target_compile_definitions(graph-tool PRIVATE
	$<$<CONFIG:Debug>:GM_DEBUG>
	$<$<CONFIG:Release>:GM_RELEASE>
	GM_SIMD
	GM_BUILD_DLL
)

# Build folder
set_target_properties(graph-tool
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${BUILD_FOLDER}/graph-tool"
	LIBRARY_OUTPUT_DIRECTORY "${BUILD_FOLDER}/graph-tool"
	RUNTIME_OUTPUT_DIRECTORY "${BUILD_FOLDER}/graph-tool"
)

target_include_directories(graph-tool PRIVATE "${CMAKE_SOURCE_DIR}/thirdparty/SFML/include")

target_link_libraries(graph-tool PRIVATE sfml-graphics sfml-window sfml-system)

set(SFML_BUILD_DIR "${CMAKE_SOURCE_DIR}/build/projects/thirdparty/SFML/lib")

add_custom_command(TARGET graph-tool POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:sfml-graphics>"
     "${BUILD_FOLDER}/graph-tool/$<CONFIGURATION>/$<TARGET_FILE_NAME:sfml-graphics>" )

add_custom_command(TARGET graph-tool POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:sfml-window>"
     "${BUILD_FOLDER}/graph-tool/$<CONFIGURATION>/$<TARGET_FILE_NAME:sfml-window>" )

add_custom_command(TARGET graph-tool POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:sfml-system>"
     "${BUILD_FOLDER}/graph-tool/$<CONFIGURATION>/$<TARGET_FILE_NAME:sfml-system>" )
