#pragma once

#include <iomanip>
#include <iostream>

using namespace std;

class ShapeDisplayer
{
public:
    virtual void display(float perimeter, float area) = 0;
};

class SquareDisplayer : public ShapeDisplayer
{
public:
    inline void display(float perimeter, float area)
    {
        cout << setw(15) << "Square" << setw(15) << "|Perimeter=" << perimeter << "|Area=" << area << "|\n";
    }
};

// class CircleDisplayer{

// };

// class RectanglesquareDisplayer{

// };