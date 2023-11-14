#pragma once

#include <vector>

#include "Shape.hpp"

using std::vector;

class ShapesSortingPerformer
{
public:
    /**
     * @brief Sort the shapes
     *
     * @param shapes is the vector of shapes
     * @param perimeter is true if sort by perimeter, false if sort by area, by default is true
     * @param ascending is true if sort in ascending order, false if sort in descending order, by default is true
     * @return is the result vector shapes
     */
    static vector<Shape *> sort(vector<Shape *> &shapes, bool perimeter = true, bool ascending = true);
};