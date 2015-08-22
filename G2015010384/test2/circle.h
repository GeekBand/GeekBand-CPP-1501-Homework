#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include"shape.h"
#include "point.h"
#define PI 3.14

class Circle: public shape
{
    Point center;
    int radius;
public:
    Circle(int _r, int _x, int _y)
    :radius(_r), center(_x, _y)
    {}

    int getRadius() const { return radius; }
    Point getCenter() const { return center; }

    int getArea()
    {
        return PI*radius*radius;
    }
};


#endif
