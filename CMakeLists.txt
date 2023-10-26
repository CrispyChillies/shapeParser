cmake_minimum_required(VERSION 3.15)
project(ShapeParser)

set(CXX_STANDARD 17)

add_executable(
    ${PROJECT_NAME}

    main.cpp
    Shape.cpp
    ShapeDisplayer.cpp
    ShapeFactory.cpp
    TextFileReader.cpp
)