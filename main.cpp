#include "Shapes.hpp"

int main()
{
    try
    {
        string filename = "../shape.txt";
        vector<Shape *> shapes = ShapesTextProvider::next(filename);
        ShapesSortingPerformer::sort(shapes);
        ShapesDisplayer::display(shapes);
    }
    catch (const invalid_argument &ia)
    {
        cout << ia.what() << endl;
    }

    return 0;
}