#include <fstream>

#include "TextFileReader.hpp"
#include "ShapeFactory.hpp"

using std::ifstream;

string TextFileLineReader::read()
{
    // Open the file
    ifstream inf(_fileName);
    string buffer;
    getline(inf, buffer);

    // Skip lines until we reach the next product
    int countLine = 0;
    while (countLine <= ShapeFactory::countProduct)
    {
        getline(inf, buffer);
        countLine++;
    }

    return buffer;
}