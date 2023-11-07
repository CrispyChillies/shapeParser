#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <vector>
#include <algorithm>

#include "TextFileReader.hpp"
#include "Shape.hpp"
#include "ShapeFactory.hpp"
#include "TextFileReader.hpp"

using namespace std;

int main()
{
    // Using TextFileReader to read a prompt
   /* TextFileReader *textFileReader = &TextFileLineReader::getInstance();
    string fileName = "shape.txt";
    textFileReader->setFileName(fileName);
    string prompt = textFileReader->read();*/

    vector<tuple<Shape*, float, float>> shapeCarry;

    ifstream inf("shape.txt");

    if (!inf)
    {
        cout << "Can't open file.\n";
        exit(1);
    }
    string buffer;
    getline(inf, buffer);
        
    string prompt;

    ShapeFactory* shapeFactory = &StringToShapeFactory::getInstance();

    while (getline(inf, prompt)) {

        // Using ShapeFactory to parse that prompt to an appropriate shape
      
        Shape* myShape = shapeFactory->parse(prompt);

        if (myShape == nullptr)
        {
            cout << "Cannot parse the prompt!" << endl;
        }
        else
        {
            // Calculate perimeter and area of the shape
            float peri = myShape->calcPerimeter();
            float are = myShape->calcArea();
            
            shapeCarry.push_back(make_tuple(myShape, peri, are));
        }
    }

    auto customComparator = [](const tuple<Shape*, float, float>& tuple1, const tuple<Shape*, float, int>& tuple2) {
        return get<2>(tuple1) < get<2>(tuple2);
        };

    sort(shapeCarry.begin(), shapeCarry.end(), customComparator);

    int n = shapeCarry.size();

    for (int i = 0; i < n; i++)
    {
        Shape* myShape = get<0>(shapeCarry[i]);

        myShape->calcPerimeter();
        myShape->calcArea();

        myShape->setDisplayer();
        myShape->display();
    }


    return 0;
}