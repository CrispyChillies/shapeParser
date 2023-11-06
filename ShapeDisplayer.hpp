#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class ShapeDisplayer
{
public:
    /// @brief Get the display string
    /// @param id is the id of the shape
    /// @param shapeName is the name of the shape
    /// @param perimeter is the perimeter of the shape
    /// @param area is the area of the shape
    /// @return the display string
    inline string getDisplayString(int id, string shapeName, float perimeter, float area)
    {
        stringstream builder;

        builder << "| " << id << " | " << shapeName << " | Perimeter=" << perimeter << " | Area=" << area << " |";

        return builder.str();
    }

    /// @brief (Pure Virtual) Display the shape
    /// @param id is the id of the shape
    /// @param perimeter is the perimeter of the shape
    /// @param area is the area of the shape
    virtual void display(int id, float perimeter, float area) = 0;
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
    /// @param id is the id of the square
    /// @param perimeter is the perimeter of the square
    /// @param area is the area of the square
    inline void display(int id, float perimeter, float area)
    {
        string displayString = getDisplayString(id, "Square", perimeter, area);
        cout << displayString << endl;
    }
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
    /// @param id is the id of the square
    /// @param perimeter is the perimeter of the square
    /// @param area is the area of the square
    inline void display(int id, float perimeter, float area)
    {
        string displayString = getDisplayString(id, "Circle", perimeter, area);
        cout << displayString << endl;
    }
};

class RectDisplayer : public ShapeDisplayer
{
     public:
    /***
     * Singleton
     */

    RectDisplayer() = default;

    /// @brief Get the instance of the Rect displayer
    /// @return the instance of the Rect displayer
    static RectDisplayer &getInstance()
    {
        static RectDisplayer instance;
        return instance;
    }

    RectDisplayer(const RectDisplayer &) = delete;
    RectDisplayer(RectDisplayer &&) = delete;
    RectDisplayer &operator=(const RectDisplayer &) = delete;
    RectDisplayer &operator=(RectDisplayer &&) = delete;

public:
    /// @brief Display the square
    /// @param id is the id of the square
    /// @param perimeter is the perimeter of the square
    /// @param area is the area of the square
    inline void display(int id, float perimeter, float area)
    {
        string displayString = getDisplayString(id, "Rectangle", perimeter, area);
        cout << displayString << endl;
    }
};