#pragma once

#include <iostream>
#include "ShapeDisplayer.hpp"

using namespace std;
class Shape
{
protected:
    int _id;                         // The id of the shape
    float _perimeter;                // The perimeter of the shape
    float _area;                     // The area of the shape
    ShapeDisplayer *_shapeDisplayer; // The displayer of the shape

public:
    inline void setId(int value)
    {
        _id = value;
    }

public:
    virtual float calcPerimeter() = 0;
    virtual float calcArea() = 0;

public:
    virtual void setDisplayer() = 0;
    virtual void display() = 0;
};

class Square : public Shape
{
private:
    float _edge;

public:
    inline void setEdge(float value)
    {
        _edge = value;
    }

public:
    /***
     * Singleton
     */

    Square() = default;

    inline static Square &getInstance(int edge)
    {
        static Square instance;
        instance.setEdge(edge);

        return instance;
    }

    Square(const Square &) = delete;
    Square(Square &&) = delete;
    Square &operator=(const Square &) = delete;
    Square &operator=(Square &&) = delete;

public:
    inline float calcPerimeter()
    {
        _perimeter = 4 * _edge;
        return _perimeter;
    }

    inline float calcArea()
    {
        _area = _edge * _edge;
        return _area;
    }

public:
    inline void setDisplayer()
    {
        _shapeDisplayer = &SquareDisplayer::getInstance();
    }

    inline void display()
    {
        _shapeDisplayer->display(_id, _perimeter, _area);
    }

public:
    static Square &parse(string prompt);
};

// class Rectangle : public Shape {

// };

// class Circle : public Shape {

// };