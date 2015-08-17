#ifndef __RECTANGLE__
#define __RECTANGLE__

#include "Share.h"
#include "Point.h"

class Rectangle: public Shape
{
    int width;
    int height;

    Point* leftUp;

public:
    Rectangle(int width, int height, int x, int y): 
        Shape(), width(width), height(height), leftUp(new Point(x, y)) {}
    
    Rectangle(const Rectangle& other):
        Shape(), width(other.width), height(other.height), leftUp(new Point(*other.leftUp)) {}
    
    Rectangle& operator=(const Rectangle& other)
    {
        this->width = other.width;
        this->height = other.height;
        this->leftUp = new Point(*other.leftUp);
        return *this;
    }

    ~Rectangle() {delete leftUp;}
};

#endif

