cmake_minimum_required(VERSION 3.14)
project(
    mdhtml
    VERSION 0.0.1
    DESCRIPTION ".md to .html translator"
    LANGUAGES CXX
)
    
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(ast)
add_subdirectory(lexer)
add_subdirectory(utils)
add_subdirectory(parser)

add_executable(mdhtml
    main.cpp
)

target_link_libraries(mdhtml
    PRIVATE
        ast
        lexer
        utils
        parser
)