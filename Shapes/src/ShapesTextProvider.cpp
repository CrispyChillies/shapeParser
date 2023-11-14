#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>

#include "ShapesTextProvider.hpp"
#include "ShapeFactory.hpp"

using std::cout;
using std::ifstream;
using std::invalid_argument;
using std::stoi;

vector<Shape *> ShapesTextProvider::next(string filename)
{
    ifstream fin(filename);

    if (!fin)
    {
        throw invalid_argument("Error: Cannot open file.");
    }

    cout << "Reading from " << filename << "...\n";

    vector<Shape *> shapes;

    string buffer;
    getline(fin, buffer);

    int countShape = stoi(buffer);

    while (countShape > 0)
    {
        getline(fin, buffer);

        Shape *shape = StringToShapeFactory::parse(buffer);

        shapes.push_back(shape);

        --countShape;
    }

    cout << "Found " << shapes.size() << " shapes\n";

    return shapes;
}