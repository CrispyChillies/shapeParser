#include "ShapeFactory.h"
#include "Shape.h"
#include <sstream>

Shape &SquareFactory::parse(string prompt)
{
    float edge;
    istringstream iss(prompt);

    int index = prompt.find_last_of('=');

    string token = prompt.substr(index + 1);

    edge = stof(token);

    Square mySquare = Square::getInstance();

    mySquare.setEdge(edge);

    return mySquare;
}