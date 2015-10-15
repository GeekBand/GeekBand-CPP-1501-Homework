#ifndef __XUN_CIRCLE__
#define __XUN_CIRCLE__

#include "Shape.h"
#include "Point.h"

#define PI 3.141592653

class Circle : public Shape
{
public:
    Circle(int _x = 0, int _y = 0, int _radius = 0, int _no = 0): center(Point(_x, _y)), radius(_radius), Shape(_no) { }
    // Override
    virtual int getArea() override {
        return PI * radius * radius;
    }
    virtual void info() override {
        std::cout << "Circle: r = " << radius << std::endl;
    }
private:
    Point center;
    int radius;
};

#endif