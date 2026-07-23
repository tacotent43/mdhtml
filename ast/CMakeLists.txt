file(
    GLOB_RECURSE SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(
    ast STATIC 
    ${SOURCES}
)

target_link_libraries(
    ast PUBLIC 
    utils
)

target_include_directories(
    ast PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)