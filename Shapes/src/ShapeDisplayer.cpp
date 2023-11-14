#include "ShapeDisplayer.hpp"

string ShapeDisplayer::getDisplayString(string shapeName, float perimeter, float area)
{
    stringstream builder;

    builder << left << setw(3) << " | " << setw(10) << shapeName << setw(16) << " | Perimeter=" << setw(10) << perimeter << setw(16) << " | Area=" << setw(10) << area << " |";

    return builder.str();
}

void SquareDisplayer::display(float perimeter, float area)
{
    string displayString = getDisplayString("Square", perimeter, area);
    cout << displayString << endl;
}

void CircleDisplayer::display(float perimeter, float area)
{
    string displayString = getDisplayString("Circle", perimeter, area);
    cout << displayString << endl;
}

void RectangleDisplayer::display(float perimeter, float area)
{
    string displayString = getDisplayString("Rectangle", perimeter, area);
    cout << displayString << endl;
}