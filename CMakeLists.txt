cmake_minimum_required(VERSION 3.20)
project(byte)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler optimizations
if(MSVC)
    add_compile_options(/Od /W4 /WX)
else()
    add_compile_options(-O0 -Wall -Wextra -Werror)
endif()

add_subdirectory(turbine)
add_subdirectory(editor)
add_subdirectory(game)