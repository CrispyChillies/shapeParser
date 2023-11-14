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

    /**
     * @brief Display the shape
     *
     */
    void display();
};

class Square : public Shape
{
private:
    float _edge;

public:
    /**
     * @brief Construct a new Square object
     *
     * @param edge is the edge of the square
     */
    Square(int edge);

    /**
     * @brief Calculate the perimeter of the square
     *
     * @return the perimeter of the square
     */
    float calcPerimeter();

    /**
     * @brief Calculate the area of the square
     *
     * @return the area of the square
     */
    float calcArea();

public:
    /**
     * @brief Set the Displayer object for the square
     *
     */
    void setDisplayer();

public:
    /**
     * @brief Parse a string prompt into a Square object
     *
     * @param prompt is the string prompt
     * @return the pointer to the Square object
     */
    static Square *parse(string prompt);
};
class Circle : public Shape
{
private:
    float _radius;

public:
    /**
     * @brief Construct a new Circle object
     *
     * @param radius is the radius of the circle
     */
    Circle(int radius);

    /**
     * @brief Calculate the perimeter of the circle
     *
     * @return the perimeter of the circle
     */
    float calcPerimeter();

    /**
     * @brief Calculate the area of the circle
     *
     * @return the area of the circle
     */
    float calcArea();

public:
    /**
     * @brief Set the Displayer object for the circle
     *
     */
    void setDisplayer();

public:
    /**
     * @brief Parse a string prompt into a Circle object
     *
     * @param prompt
     * @return Circle*
     */
    static Circle *parse(string prompt);
};
class Rectangle : public Shape
{
private:
    float _height;
    float _width;

public:
    /**
     * @brief Construct a new Rectangle object
     *
     * @param height is the height of the rectangle
     * @param width is the width of the rectangle
     */
    Rectangle(float height, float width);

    /**
     * @brief Calculate the perimeter of the rectangle
     *
     * @return the perimeter of the rectangle
     */
    float calcPerimeter();

    /**
     * @brief
     *
     * @return the area of the rectangle
     */
    float calcArea();

public:
    /**
     * @brief Set the Displayer object for the rectangle
     *
     */
    void setDisplayer();

public:
    /**
     * @brief Parse a string prompt into a Rectangle object
     *
     * @param prompt
     * @return Rectangle*
     */
    static Rectangle *parse(string prompt);
};