#include <iostream>
#include "ShapeDisplayer.h"

using namespace std;

class Shape {
    protected:    
        float _perimeter;
        float _area;
        ShapeDisplayer* shapeDisplayer;
    public:
        virtual float calcPerimeter() = 0;
        virtual float calcArea() = 0;
        virtual void display() = 0;
        virtual void setDisplayer(ShapeDisplayer* shapeDisplayer) = 0;

};

class Square : public Shape {
    private:
        float _edge;
    public:
        inline float calcPerimeter(){
            _perimeter = 4  * _edge;
            return _perimeter;
        }
        inline float calcArea()
        {
            _area = _edge * _edge;
            return _area;
        }
        inline void display()
        {
            shapeDisplayer->display(_perimeter, _area);
        }
        inline void setDisplayer(ShapeDisplayer* shapeDisplayer)
        {
            shapeDisplayer = new SquareDisplayer();
        }
        inline static Square& getInstance()
        {   
            static Square instance;
            
            return instance;
        }
        inline void setEdge(float value)
        {
            _edge = value;
        }
};

// class Rectangle : public Shape {

// };

// class Circle : public Shape {


// };