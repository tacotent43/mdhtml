file(GLOB SOURCES "src/*.cpp")

add_library(
    parser STATIC 
    ${SOURCES}
)

target_link_libraries(
    parser PUBLIC
    utils lexer ast
)

target_include_directories(
    parser PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)