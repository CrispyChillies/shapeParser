#pragma once

#include <vector>
#include <string>

#include "Shape.hpp"

using std::string;
using std::vector;

class ShapesTextProvider
{
public:
    static vector<Shape *> next(string filename);
};