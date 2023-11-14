#pragma once

#include <vector>

#include "Shape.hpp"

using std::vector;

class ShapesDisplayer
{
public:
    /**
     * @brief Display the shapes
     *
     * @param shapes is the vector of shapes
     */
    static void display(const vector<Shape *> &shapes);
};