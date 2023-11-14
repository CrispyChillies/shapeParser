#pragma once

#include <vector>

#include "Shape.hpp"

using std::vector;

class ShapesDisplayer
{
public:
    static void display(const vector<Shape *> &shapes);
};