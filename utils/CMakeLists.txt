file(GLOB SOURCES "source/*.cpp")

add_library(utils STATIC ${SOURCES})
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)