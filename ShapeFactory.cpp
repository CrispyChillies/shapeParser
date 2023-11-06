#include <sstream>

#include "ShapeFactory.hpp"

Shape *StringToShapeFactory::parse(string prompt)
{
    Shape *product = nullptr;

    // Check if the substring "Square" is in the prompt
    if (prompt.find("Square") != std::string::npos)
    {
        product = &Square::parse(prompt);
    }
    // Check if the substring "Circle" is in the prompt
    else if (prompt.find("Circle") != std::string::npos)
    {
        product = &Circle::parse(prompt);
    }
    // Check if the substring "Rectangle" is in the prompt
    else if (prompt.find("Rectangle") != std::string::npos)
    {
        product = &Rect::parse(prompt);
    }

    if (product != nullptr)
    {
        ++countProduct;
        product->setId(countProduct);
    }

    return product;
}