file(
    GLOB_RECURSE SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(
    lexer STATIC 
    ${SOURCES}
)

target_link_libraries(
    lexer PUBLIC 
    utils
)

target_include_directories(
    lexer PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)