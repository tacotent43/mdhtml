file(GLOB SOURCES_BLOCKNODE "BlockNode/source/*.cpp")
file(GLOB SOURCES_INLINENODE "InlineNode/source/*.cpp")

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