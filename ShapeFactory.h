#pragma once

#include "Shape.h"
#include <string>

using namespace std;

class ShapeFactory
{
protected:
    int _count = 0;

public:
    virtual Shape &parse(string prompt) = 0;
    void addCount()
    {
        _count++;
    }
};

class SquareFactory : public ShapeFactory
{
public:
    Shape &parse(string prompt);
    inline static ShapeFactory &getInstance()
    {
        static SquareFactory instance;
        return instance;
    }
};