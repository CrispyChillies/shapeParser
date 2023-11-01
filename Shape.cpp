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