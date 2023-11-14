#pragma once

#include <iostream>
#include "ShapeDisplayer.hpp"

const float PI = 3.14;

using namespace std;
class Shape
{
protected:
    float _perimeter;                // The perimeter of the shape
    float _area;                     // The area of the shape
    ShapeDisplayer *_shapeDisplayer; // The displayer of the shape

public:
    virtual float calcPerimeter() = 0;
    virtual float calcArea() = 0;
    float getPerimeter();
    float getArea();

public:
    virtual void setDisplayer() = 0;
    void display();
};

class Square : public Shape
{
private:
    float _edge;

public:
    Square(int edge);
    float calcPerimeter();
    float calcArea();

public:
    void setDisplayer();

public:
    static Square *parse(string prompt);
};
class Circle : public Shape
{
private:
    float _radius;

public:
    Circle(int radius);
    float calcPerimeter();
    float calcArea();

public:
    void setDisplayer();

public:
    static Circle *parse(string prompt);
};
class Rectangle : public Shape
{
private:
    float _height;
    float _width;

public:
    Rectangle(float height, float width);
    float calcPerimeter();
    float calcArea();

public:
    void setDisplayer();

public:
    static Rectangle *parse(string prompt);
};