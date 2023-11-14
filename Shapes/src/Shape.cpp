#include "Shape.hpp"
#include <algorithm>

float Shape::getPerimeter()
{
    return _perimeter;
}

float Shape::getArea()
{
    return _area;
}

void Shape::display()
{
    _shapeDisplayer->display(_perimeter, _area);
}

Square::Square(int edge)
{
    _edge = edge;

    calcPerimeter();
    calcArea();
    setDisplayer();
}

float Square::calcPerimeter()
{
    _perimeter = 4 * _edge;
    return _perimeter;
}

float Square::calcArea()
{
    _area = _edge * _edge;
    return _area;
}

void Square::setDisplayer()
{
    _shapeDisplayer = &SquareDisplayer::getInstance();
}

Square *Square::parse(string prompt)
{
    // Sample prompt: Square: a=12
    // Delete all the whitespace characters
    prompt.erase(remove_if(prompt.begin(), prompt.end(), ::isspace), prompt.end());

    // Sample prompt: Square:a=12
    // Get the number after the "=" character
    string edgeString = prompt.substr(prompt.find("=") + 1);

    // Convert the string to float
    float edge = stof(edgeString);

    Square *square = new Square(edge);

    // Return the Square instance
    return square;
}

Circle::Circle(int radius)
{
    _radius = radius;

    calcPerimeter();
    calcArea();
    setDisplayer();
}

float Circle::calcPerimeter()
{
    _perimeter = 2 * PI * _radius;
    return _perimeter;
}

float Circle::calcArea()
{
    _area = PI * _radius * _radius;
    return _area;
}

void Circle::setDisplayer()
{
    _shapeDisplayer = &CircleDisplayer::getInstance();
}

Circle *Circle::parse(string prompt)
{
    prompt.erase(remove_if(prompt.begin(), prompt.end(), ::isspace), prompt.end());

    string radiusString = prompt.substr(prompt.find("=") + 1);

    // Convert the string to float
    float radius = stof(radiusString);

    // Create a new Square instance
    Circle *circle = new Circle(radius);

    // Return the Circle instance
    return circle;
}

Rectangle::Rectangle(float height, float width)
{
    _height = height;
    _width = width;

    calcPerimeter();
    calcArea();
    setDisplayer();
}

float Rectangle::calcPerimeter()
{
    _perimeter = (_width + _height) * 2;
    return _perimeter;
}

float Rectangle::calcArea()
{
    _area = _width * _height;
    return _area;
}

void Rectangle::setDisplayer()
{
    _shapeDisplayer = &RectangleDisplayer::getInstance();
}

Rectangle *Rectangle::parse(string prompt)
{
    prompt.erase(remove_if(prompt.begin(), prompt.end(), ::isspace), prompt.end());

    int index = prompt.find_first_of('=');

    string widthString = prompt.substr(index + 1);
    float w = stof(widthString);

    index = prompt.find_last_of('=');

    string heightString = prompt.substr(index + 1);
    float h = stof(heightString);

    Rectangle *rect = new Rectangle(w, h);

    return rect;
}