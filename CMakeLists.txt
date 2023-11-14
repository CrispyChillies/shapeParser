cmake_minimum_required(VERSION 3.15)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")

project(ShapeParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

# Add Shapes library
add_library(Shapes SHARED IMPORTED)

set_target_properties(Shapes PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/Shapes/libShapes.dylib"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/Shapes"
        )

target_link_libraries(${PROJECT_NAME} Shapes)