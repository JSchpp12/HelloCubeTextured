# CMakeList.txt : CMake project for HelloSquare, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(Vulkan REQUIRED FATAL_ERROR)

# Add source to this project's executable.
add_executable (HelloSquare "src/HelloSquare.cpp" "src/HelloSquare.h" "src/HelloSquareApplication.cpp" "src/HelloSquareApplication.h" "src/VertexColor.h" "src/VertexColor.cpp" "src/Vertex.h" "src/VulkanObject.h" "src/VulkanObject.cpp")

set_property(TARGET HelloSquare PROPERTY CXX_STANDARD 17)

#configure_file("${cmake_source_dir}/shaders/vertshader_7.vert" "${cmake_current_binary_dir}" copyonly)
#configure_file("${cmake_source_dir}/shaders/fragShader_3.frag" "${cmake_current_binary_dir}" copyonly)

add_subdirectory("external/glfw")
add_subdirectory("external/glm")

#compile shaders 
if (${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "AMD64")
  set(GLSL_VALIDATOR "$ENV{VULKAN_SDK}/Bin/glslangValidator.exe")
else()
  set(GLSL_VALIDATOR "$ENV{VULKAN_SDK}/Bin32/glslangValidator.exe")
endif()

file(GLOB_RECURSE GLSL_SOURCE_FILES
    "shaders/*.frag"
    "shaders/*.vert"
    )

foreach(GLSL ${GLSL_SOURCE_FILES})
  get_filename_component(FILE_NAME ${GLSL} NAME)
  set(SPIRV "${PROJECT_BINARY_DIR}/shaders/${FILE_NAME}.spv")
  add_custom_command(
    OUTPUT ${SPIRV}
    COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_BINARY_DIR}/shaders/"
    COMMAND ${GLSL_VALIDATOR} -V ${GLSL} -o ${SPIRV}
    DEPENDS ${GLSL})
  list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach(GLSL)

add_custom_target(
    Shaders 
    DEPENDS ${SPIRV_BINARY_FILES}
    )

add_dependencies(HelloSquare Shaders)

add_custom_command(TARGET HelloSquare POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:HelloSquare>/shaders/"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_BINARY_DIR}/shaders"
        "$<TARGET_FILE_DIR:HelloSquare>/shaders"
)


if (WIN32)
	target_include_directories(HelloSquare PUBLIC "${PROJECT_BINARY_DIR}/"
												  "${PROJECT_BINARY_DIR}/classes/"
												  "${PROJECT_BINARY_DIR}/interfaces/"
												  "${PROJECT_BINARY_DIR}/structs/"
												  "external/glfw/include"
												  "external/glm/"
												  "${Vulkan_INCLUDE_DIRS}")
	target_link_libraries(HelloSquare "${Vulkan_LIBRARIES}"
									  glfw "${GLFW_LIBRARIES}"
									  )
	endif (WIN32)

if (UNIX)						  
	find_package(glm REQUIRED FATAL_ERROR)
	target_include_directories(HelloSquare PUBLIC 
													"${PROJECT_BINARY_DIR}"
													"${GLFW_INCLUDE_DIR}"
													"${GLM_INCLUDE_DIR}"
													"${Vulkan_INCLUDE_DIRS}")
	target_link_libraries(HelloSquare)
													
endif (UNIX)

# TODO: Add tests and install targets if needed.
