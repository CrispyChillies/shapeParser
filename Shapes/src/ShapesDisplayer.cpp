#include "ShapesDisplayer.hpp"

void ShapesDisplayer::display(const vector<Shape *> &shapes)
{
    for (int i = 0; i < shapes.size(); i++)
    {
        cout << left << setw(5) << " | " << i + 1;
        shapes[i]->display();
    }
}