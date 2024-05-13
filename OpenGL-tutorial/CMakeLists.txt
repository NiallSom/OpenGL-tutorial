cmake_minimum_required(VERSION 3.28)
project(OpenGL-tutorial)

set(CMAKE_CXX_STANDARD 17)

# Add executable
add_executable(Graphics main.cpp
        glad.c
)

target_link_libraries(Graphics -lfreeglut -lglew32 -lopengl32 glfw3 libglfw3.a)
