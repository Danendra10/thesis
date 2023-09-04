cmake_minimum_required(VERSION 3.12)
project(THESIS)

find_package(OpenCV REQUIRED)
include_directories(
    include
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(main src/main.cpp)
target_link_libraries(main )

# target_link_libraries(main glfw)
# target_link_libraries(main ${GLEW_LIBRARIES})
# target_link_libraries(main OpenGL::GL)
