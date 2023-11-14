#pragma once

#include <vector>
#include <string>

#include "Shape.hpp"

using std::string;
using std::vector;

class ShapesTextProvider
{
public:
    /**
     * @brief Read shapes from a text file
     *
     * @param filename is text file name
     * @return the vector of shapes pointers
     */
    static vector<Shape *> next(string filename);
};