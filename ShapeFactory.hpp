#pragma once

#include <string>

#include "Shape.hpp"

using namespace std;

class ShapeFactory
{
public:
    inline static int countProduct = 0;

public:
    virtual Shape *parse(string prompt) = 0;
};

class StringToShapeFactory : public ShapeFactory
{
public:
    /***
     * Singleton
     */

    StringToShapeFactory() = default;

    static StringToShapeFactory &getInstance()
    {
        static StringToShapeFactory instance;
        return instance;
    }

    StringToShapeFactory(const StringToShapeFactory &) = delete;
    StringToShapeFactory(StringToShapeFactory &&) = delete;
    StringToShapeFactory &operator=(const StringToShapeFactory &) = delete;
    StringToShapeFactory &operator=(StringToShapeFactory &&) = delete;

public:
    Shape *parse(string prompt);
};
