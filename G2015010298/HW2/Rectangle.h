#ifndef __XUN_RECTANGLE__
#define __XUN_RECTANGLE__

#include "Shape.h"
#include "Point.h"

class Rectangle: public Shape
{
public:
    // Constructor
    Rectangle(int _width = 0, int _height = 0, int _x = 0, int _y = 0, int _no = 0): width(_width), height(_height), leftUp(Point(_x, _y)), Shape(_no) { }
    // Override
    virtual int getArea() override {
        return width * height;
    }
    virtual void info() override {
        std::cout << "Rectangle: w = " << width << " h = " << height << std::endl;
    }
private:
    int width;
    int height;
    Point leftUp;
};


#endif