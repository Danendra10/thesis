cmake_minimum_required(VERSION 3.27)
project(THESIS)

add_compile_options(-std=c++17)

find_package(OpenCV REQUIRED)
find_package(yaml-cpp REQUIRED)

IF(OpenCV_FOUND)
    message(STATUS "OpenCV version: ${OpenCV_VERSION}")
ENDIF()

IF(yaml-cpp_FOUND)
    message(STATUS "yaml-cpp version: ${yaml-cpp_VERSION}")
    message(STATUS "Yaml-cpp dir:     /opt/homebrew/Cellar/yaml-cpp/0.8.0/include")
ENDIF()

include_directories(
    include
    ${OpenCV_INCLUDE_DIRS}
    /opt/homebrew/Cellar/yaml-cpp/0.8.0/include
)

link_directories(
    /opt/homebrew/Cellar/yaml-cpp/0.8.0/lib
)

add_executable(main src/main.cpp)
target_link_libraries(main ${OpenCV_LIBS} ${YAML_CPP_LIBRARIES})

# target_link_libraries(main glfw)
# target_link_libraries(main ${GLEW_LIBRARIES})
# target_link_libraries(main OpenGL::GL)
