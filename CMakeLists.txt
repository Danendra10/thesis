cmake_minimum_required(VERSION 3.12)
project(THESIS)

# Find GLFW package (installed via Brew)
find_package(glfw3 3.3 REQUIRED)

# Find GLEW package (installed via Brew)
find_package(GLEW REQUIRED)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Include directories for GLFW, GLEW, and OpenGL
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})

# Add your source files here
set(SOURCES main.cpp)

add_executable(OpenGLExample ${SOURCES})

# Link libraries (GLFW, GLEW, OpenGL)
target_link_libraries(OpenGLExample glfw)
target_link_libraries(OpenGLExample ${GLEW_LIBRARIES})
target_link_libraries(OpenGLExample OpenGL::GL)
