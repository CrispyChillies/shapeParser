#include <algorithm>
#include "Shape.hpp"

Square &Square::parse(string prompt)
{
    // Sample prompt: Square: a=12
    // Delete all the whitespace characters
    prompt.erase(remove_if(prompt.begin(), prompt.end(), ::isspace), prompt.end());

    // Sample prompt: Square:a=12
    // Get the number after the "=" character
    string edgeString = prompt.substr(prompt.find("=") + 1);

    // Convert the string to float
    float edge = stof(edgeString);

    // Create a new Square instance
    Square *square = &Square::getInstance(edge);

    // Return the Square instance
    return *square;
}

Circle &Circle::parse(string prompt)
{
    prompt.erase(remove_if(prompt.begin(), prompt.end(), ::isspace), prompt.end());

    string radiusString = prompt.substr(prompt.find("=") + 1);

    // Convert the string to float
    float radius = stof(radiusString);

    // Create a new Square instance
    Circle* circle = &Circle::getInstance(radius);

    // Return the Circle instance
    return *circle;
}

Rect& Rect::parse(string prompt)
{
    prompt.erase(remove_if(prompt.begin(), prompt.end(), ::isspace), prompt.end());
    int index = prompt.find_first_of('=');
    string widthString = prompt.substr(index+1);
    float w = stof(widthString);

    index = prompt.find_last_of('=');
    string heightString = prompt.substr(index+1);
    float h = stof(heightString);

    Rect* rect = &Rect::getInstance(w, h);

    return *rect;
}