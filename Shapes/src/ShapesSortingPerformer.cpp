#include <algorithm>

#include "ShapesSortingPerformer.hpp"

vector<Shape *> ShapesSortingPerformer::sort(vector<Shape *> &shapes, bool perimeter, bool ascending)
{
    if (perimeter)
    {
        if (ascending)
        {
            std::sort(shapes.begin(), shapes.end(), [](Shape *a, Shape *b)
                      { return a->getPerimeter() < b->getPerimeter(); });
        }
        else
        {
            std::sort(shapes.begin(), shapes.end(), [](Shape *a, Shape *b)
                      { return a->getPerimeter() > b->getPerimeter(); });
        }
    }
    else
    {
        if (ascending)
        {
            std::sort(shapes.begin(), shapes.end(), [](Shape *a, Shape *b)
                      { return a->getArea() < b->getArea(); });
        }
        else
        {
            std::sort(shapes.begin(), shapes.end(), [](Shape *a, Shape *b)
                      { return a->getArea() > b->getArea(); });
        }
    }

    return shapes;
}