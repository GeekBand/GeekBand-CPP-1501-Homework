#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include"shape.h"
#include "point.h"

class Rectangle: public shape
{
    int width;
    int height;
    Point leftUp;
public:
    Rectangle(int _w, int _h, int _x, int _y)
    :width(_w), height(_h), leftUp(_x, _y)
    {}
        
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    Point getPoint() const { return leftUp; }
    
    
    int getArea()
    {
        return width*height;
    }
};



#endif
