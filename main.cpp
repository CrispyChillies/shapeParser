#include "ShapeFactory.hpp"
#include "TextFileReader.hpp"

int main()
{
    // Using TextFileReader to read a prompt
    TextFileReader *textFileReader = &TextFileLineReader::getInstance();
    string fileName = "../shape.txt";
    textFileReader->setFileName(fileName);
    string prompt = textFileReader->read();

    // Using ShapeFactory to parse that prompt to an appropriate shape
    ShapeFactory *shapeFactory = &StringToShapeFactory::getInstance();
    Shape *myShape = shapeFactory->parse(prompt);

    if (myShape == nullptr)
    {
        cout << "Cannot parse the prompt!" << endl;
    }
    else
    {
        // Calculate perimeter and area of the shape
        myShape->calcPerimeter();
        myShape->calcArea();

        // Set displayer for the shape
        myShape->setDisplayer();
        myShape->display();
    }

    return 0;
}