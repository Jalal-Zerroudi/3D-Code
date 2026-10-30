cmake_minimum_required(VERSION 3.16)

project(3DCode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(3d-code 3D_Haram.cpp)

target_link_libraries(3d-code
    PRIVATE
        OpenGL::GL
        OpenGL::GLU
        GLUT::GLUT
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(3d-code PRIVATE -Wall -Wextra -pedantic)
elseif(MSVC)
    target_compile_options(3d-code PRIVATE /W4)
endif()
