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

    inline static Square &getInstance(float edge)
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

class Rect : public Shape {
    private:
    float _height;
    float _width;

public:
    inline void setHeight(float value)
    {
        _height = value;
    }
    inline void setWidth(float value)
    {
        _width = value;
    }

public:
    /***
     * Singleton
     */

    Rect() = default;

    inline static Rect &getInstance(float width, float height)
    {
        static Rect instance;
        instance.setHeight(height);
        instance.setWidth(width);

        return instance;
    }

    Rect(const Rect &) = delete;
    Rect(Rect &&) = delete;
    Rect &operator=(const Rect &) = delete;
    Rect &operator=(Rect &&) = delete;

public:
    inline float calcPerimeter()
    {
        _perimeter = (_width + _height) * 2;
        return _perimeter;
    }

    inline float calcArea()
    {
        _area = _width * _height;
        return _area;
    }

public:
    inline void setDisplayer()
    {
        _shapeDisplayer = &RectDisplayer::getInstance();
    }

    inline void display()
    {
        _shapeDisplayer->display(_id, _perimeter, _area);
    }

public:
    static Rect &parse(string prompt);
};

class Circle : public Shape {
    private:
    float _radius;
    const float pi = 3.14;

public:
    inline void setRadius(float value)
    {
        _radius = value;
    }

public:
    /***
     * Singleton
     */

    Circle() = default;

    inline static Circle &getInstance(float radius)
    {
        static Circle instance;
        instance.setRadius(radius);

        return instance;
    }

    Circle(const Circle &) = delete;
    Circle(Circle &&) = delete;
    Circle &operator=(const Circle &) = delete;
    Circle &operator=(Circle &&) = delete;

public:
    inline float calcPerimeter()
    {
        _perimeter = 2 * pi * _radius;
        return _perimeter;
    }

    inline float calcArea()
    {
        _area = pi * _radius * _radius;
        return _area;
    }

public:
    inline void setDisplayer()
    {
        _shapeDisplayer = &CircleDisplayer::getInstance();
    }

    inline void display()
    {
        _shapeDisplayer->display(_id, _perimeter, _area);
    }

public:
    static Circle &parse(string prompt);

};