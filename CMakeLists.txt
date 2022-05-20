# CMakeList.txt : CMake project for HelloSquare, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("HelloSquareTextured")

find_package(Vulkan REQUIRED FATAL_ERROR)
#find_package(Vulkan COMPONENTS glslc)

#TODO: NEED TO USE SPIRV-TOOLS IN VULKAN SDK...build too slow
#add_subdirectory("external/spirvheaders")
add_subdirectory("external/glfw")
add_subdirectory("external/glm")
add_subdirectory("external/glslang")


find_library(glslang_LIBRARY NAMES glslang HINTS "$ENV{VULKAN_SDK}/lib")
find_library(glslang_LIBRARY_DEBUG NAMES glslangd HINTS "$ENV{VULKAN_SDK}/lib")
find_library(glslang_HLSL NAMES hlsl HINTS "$ENV{VULKAN_SDK}/lib")
find_library(glslang_HLSL_DEBUG NAMES hlsld HINTS "$ENV{VULKAN_SDK}/lib")
find_library(glslang_OSDEPENDENT NAMES osdependent HINTS "$ENV{VULKAN_SDK}/lib")
find_library(glslang_OSDEPENDENT_DEBUG NAMES osdependentd HINTS "$ENV{VULKAN_SDK}/lib")
find_library(glslang_OGLCOMPILER NAMES oglcompiler HINTS "$ENV{VULKAN_SDK}/lib")
find_library(glslang_OGLCOMPILER_DEBUG NAMES oglcompilerd HINTS "$ENV{VULKAN_SDK}/lib")
find_library(glslang_SPIRV NAMES spirv HINTS "$ENV{VULKAN_SDK}/lib")
find_library(glslang_SPIRV_DEBUG NAMES spirvd HINTS "$ENV{VULKAN_SDK}/lib")
find_library(glslang_machineind NAME machineindependent HINTS "$ENV{VULKAN_SDK}/lib")
find_library(glslang_machineind_DEBUG NAME machineindependentd HINTS "$ENV{VULKAN_SDK}/lib")
find_library(SPIRV_TOOLS_STATIC NAME spirv-tools-static HINTS "$ENV{VULKAN_SDK}/lib")
find_library(SPIRV_TOOLS_STATIC NAME spirv-tools-staticd HINTS "$ENV{VULKAN_SDK}/lib")

link_directories(HelloSquareTextured "$ENV{VULKAN_SDK}/lib")

#link_directories("$ENV{VULKAN_SDK}/lib")
#TODO: Link against libs in vulkan sdk instead of submodule if they are available (findGLSLANG.cmake)-- especially for GLSLANG
#set(GLSLANG_LINK_LIBS ${glslang_LIBRARY_DEBUG} ${glslang_OGLCOMPILER} ${glslang_SPIRV} ${glslang_HLSL} ${glslang_OSDEPENDENT} ${glslang_machineind} GenericCodeGen SPIRV-Tools-opt SPIRV-Tools SPVRemapper)
#set(GLSLANG_LINK_LIBS_DEBUG ${glslang_LIBRARY_DEBUG} ${glslang_OGLCOMPILER_DEBUG} ${glslang_SPIRV_DEBUG} ${glslang_HLSL_DEBUG} ${glslang_OSDEPENDENT_DEBUG} ${glslang_machineind_DEBUG} GenericCodeGend SPIRV-Tools-optd SPIRV-Toolsd SPVRemapperd )

#[[
set(LIBRARIES
		glslang 
		HLSL
		OSDependent
		OGLCompiler
		spirv
		glslang-default-resource-limits
)
set(LIBRARIES_DEBUG
		glslangd 
		HLSLd
		OSDependentd
		OGLCompilerd
		spirvd
		glslang-default-resource-limitsd
)]]
#set(GLSLANG_LINK_LIBS_DEBUG glslang ${glslang_OGLCOMPILER_DEBUG} SPIRV ${glslang_HLSL_DEBUG} ${glslang_OSDEPENDENT_DEBUG} MachineIndependentd GenericCodeGend SPIRV-Tools-optd SPIRV-Toolsd SPVRemapperd )

# Add source to this project's executableo.
add_executable (HelloSquareTextured "src/HelloSquare.cpp" "src/HelloSquare.h" "src/HelloSquareApplication.cpp" "src/HelloSquareApplication.h" "src/VertexColor.h" "src/VertexColor.cpp" "src/Vertex.h" "src/VulkanObject.h" "src/VulkanObject.cpp" "src/Shader.h" "src/Shader.cpp" "src/GLSLShader.h" "src/GLSLShader.cpp" "src/Enums.h" "src/GLSlangHelper.h"  "src/Constants.h")

set_property(TARGET HelloSquareTextured PROPERTY CXX_STANDARD 17)

#configure_file("${cmake_source_dir}/shaders/vertshader_7.vert" "${cmake_current_binary_dir}" copyonly)
#configure_file("${cmake_source_dir}/shaders/fragShader_3.frag" "${cmake_current_binary_dir}" copyonly)

#TODO: NEED BETTER SOLUTION FOR MEDIA FILES
file(COPY "${CMAKE_SOURCE_DIR}/media/images/texture.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/media/images")
file(COPY "${CMAKE_SOURCE_DIR}/media/shaders/fragShader.frag" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/media/shaders")
file(COPY "${CMAKE_SOURCE_DIR}/media/shaders/vertShader.vert" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/media/shaders")

file(GLOB_RECURSE GLSL_SOURCE_FILES
    "media/shaders/*.frag"
    "media/shaders/*.vert"
)

message("Is vulkan found? ${VULKAN_FOUND}")
message("Where is it ${Vulkan_LIBRARY}")
message("test: ${glslang_SPIRV_DEBUG}")
target_include_directories(HelloSquareTextured PRIVATE "${PROJECT_BINARY_DIR}/"
												"external/glfw/include"
												"external/glm"
												"external/stb"
												"${Vulkan_INCLUDE_DIRS}")

target_link_directories(HelloSquareTextured 
	PRIVATE external/glslang/SPIRV
	PRIVATE external/glslang/glslang
	PRIVATE external/spirvtools/source
	PRIVATE external/glslang/hlsl
	PRIVATE external/glslang/OSDependent/Windows
	PRIVATE external/glslang/OGLCompilersDLL
)


target_link_libraries(HelloSquareTextured ${Vulkan_LIBRARIES}
						glfw ${GLFW_LIBRARIES}
)

#libs needed for glfw
target_link_libraries(HelloSquareTextured 
	glslang 
	HLSL 
	OSDependent
	OGLCompiler
	SPIRV
)

#
#target_link_libraries(HelloSquareTextured
#						glslang					
#)

if (UNIX)						  
	find_package(glm REQUIRED FATAL_ERROR)
	target_include_directories(HelloSquareTextured PUBLIC 
													"${PROJECT_BINARY_DIR}"
													"${GLFW_INCLUDE_DIR}"
													"${GLM_INCLUDE_DIR}"
													"${Vulkan_INCLUDE_DIRS}")
	target_link_libraries(HelloSquareTextured)

	target_link_libraries(HelloSquareTextured 
		

	)
													
endif (UNIX)

#pass needed directories to application


# TODO: Add tests and install targets if needed.
