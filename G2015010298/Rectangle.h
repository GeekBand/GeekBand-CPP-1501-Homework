#ifndef __RECTANGLE__
#define __RECTANGLE__

#include "Shape.h"
#include "Point.h"

class Rectangle: public Shape
{
public:
    // Constructor
    Rectangle(int width, int height, int x, int y):
        Shape(),
        width(width > 0 ? width : 0), height(height > 0 ? height : 0),
        leftUp(new Point(x, y)) { };
    
    /*  --------------------  BIG THREE  -----------------------  */
    
    // Copy Contructor
    Rectangle(const Rectangle& other);
    // Copy Assignment Operator
    Rectangle& operator = (const Rectangle& other);
    // Deconstructor
    ~Rectangle() { };
    
    // Getter
    Point* getleftup() const { return leftUp; }
    int w() const { return width; }
    int h() const { return height; }
private:
    int width;
    int height;
    Point* leftUp;
};

inline
Rectangle::Rectangle (const Rectangle& other)
{
    Shape();
    width = other.width;
    height = other.height;
    leftUp = new Point(other.leftUp->xVal(), other.leftUp->yVal());
}

inline
Rectangle& Rectangle::operator = (const Rectangle& other)
{
    if (this == &other)
        return *this;
    
    *(this->leftUp) = *(other.leftUp); // Determined by copy op= implement in Point Class
    this->width = other.w();
    this->height = other.h();
    return *this;
}

#endif