file(GLOB_RECURSE ast ${CMAKE_CURRENT_SOURCE_DIR})

add_library(
    ast STATIC 
    ${SOURCES_BLOCKNODE} 
    ${SOURCES_INLINENODE}
)

target_include_directories(
    ast PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/BlockNode/include
    ${CMAKE_CURRENT_SOURCE_DIR}/InlineNode/include
)