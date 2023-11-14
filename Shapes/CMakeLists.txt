cmake_minimum_required(VERSION 3.15)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")

project(Shapes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    ${PROJECT_NAME} SHARED

    src/Shape.cpp
    src/ShapeDisplayer.cpp
    src/ShapeFactory.cpp
    src/ShapesTextProvider.cpp
    src/ShapesSortingPerformer.cpp
    src/ShapesDisplayer.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC .)