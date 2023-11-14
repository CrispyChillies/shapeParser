#pragma once

#include <string>

#include "Shape.hpp"

using namespace std;
class StringToShapeFactory
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
    /**
     * @brief Parse the string to shape
     *
     * @param prompt
     * @return the shape
     */
    static Shape *parse(string prompt);
};
