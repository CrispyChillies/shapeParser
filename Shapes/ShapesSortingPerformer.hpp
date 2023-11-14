#pragma once

#include <vector>

#include "Shape.hpp"

using std::vector;

class ShapesSortingPerformer
{
public:
    static vector<Shape *> sort(vector<Shape *> &shapes, bool perimeter = true, bool ascending = true);
};