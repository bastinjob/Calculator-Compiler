cmake_minimum_required(VERSION 3.12)
project(TinyCalculatorCompiler VERSION 0.1.0 LANGUAGES CXX)


#Enable testing and strict warnings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Werror)

#Add compiler library
add_library(compiler
    src/Lexer.cpp 
    src/Parser.cpp 
    src/CodeGen.cpp 
)

target_include_directories(compiler PUBLIC include)


#Add executable
add_executable(tinycc main.cpp)
target_link_libraries(tiny_cc compiler)

# Enable unit testing with Catch2
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.0
)
FetchContent_MakeAvailable(catch2)