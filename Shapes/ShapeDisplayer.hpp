#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

using std::cout, std::endl;
using std::left, std::setw, std::internal;
using std::string, std::stringstream;

class ShapeDisplayer
{
public:
    /// @brief Get the display string
    /// @param shapeName is the name of the shape
    /// @param perimeter is the perimeter of the shape
    /// @param area is the area of the shape
    /// @return the display string
    string getDisplayString(string shapeName, float perimeter, float area);

    /// @brief (Pure Virtual) Display the shape
    /// @param perimeter is the perimeter of the shape
    /// @param area is the area of the shape
    virtual void display(float perimeter, float area) = 0;
};

class SquareDisplayer : public ShapeDisplayer
{
public:
    /***
     * Singleton
     */

    SquareDisplayer() = default;

    /// @brief Get the instance of the square displayer
    /// @return the instance of the square displayer
    static SquareDisplayer &getInstance()
    {
        static SquareDisplayer instance;
        return instance;
    }

    SquareDisplayer(const SquareDisplayer &) = delete;
    SquareDisplayer(SquareDisplayer &&) = delete;
    SquareDisplayer &operator=(const SquareDisplayer &) = delete;
    SquareDisplayer &operator=(SquareDisplayer &&) = delete;

public:
    /// @brief Display the square
    /// @param perimeter is the perimeter of the square
    /// @param area is the area of the square
    void display(float perimeter, float area);
};

class CircleDisplayer : public ShapeDisplayer
{
public:
    /***
     * Singleton
     */

    CircleDisplayer() = default;

    /// @brief Get the instance of the Circle displayer
    /// @return the instance of the Circle displayer
    static CircleDisplayer &getInstance()
    {
        static CircleDisplayer instance;
        return instance;
    }

    CircleDisplayer(const CircleDisplayer &) = delete;
    CircleDisplayer(CircleDisplayer &&) = delete;
    CircleDisplayer &operator=(const CircleDisplayer &) = delete;
    CircleDisplayer &operator=(CircleDisplayer &&) = delete;

public:
    /// @brief Display the square
    /// @param perimeter is the perimeter of the square
    /// @param area is the area of the square
    void display(float perimeter, float area);
};

class RectangleDisplayer : public ShapeDisplayer
{
public:
    /***
     * Singleton
     */

    RectangleDisplayer() = default;

    /// @brief Get the instance of the Rectangle displayer
    /// @return the instance of the Rectangle displayer
    static RectangleDisplayer &getInstance()
    {
        static RectangleDisplayer instance;
        return instance;
    }

    RectangleDisplayer(const RectangleDisplayer &) = delete;
    RectangleDisplayer(RectangleDisplayer &&) = delete;
    RectangleDisplayer &operator=(const RectangleDisplayer &) = delete;
    RectangleDisplayer &operator=(RectangleDisplayer &&) = delete;

public:
    /// @brief Display the square
    /// @param perimeter is the perimeter of the square
    /// @param area is the area of the square
    void display(float perimeter, float area);
};