#ifndef __XUN_RECTANGLE__
#define __XUN_RECTANGLE__

#include "Shape.h"
#include "Point.h"

class Rectangle: public Shape
{
public:
    // Constructor
    Rectangle(int _width = 0, int _height = 0, int _x = 0, int _y = 0, int _no = 0): width(_width), height(_height), leftUp(new Point(_x, _y)), Shape(_no) { }
    
    /*  --------------------  BIG THREE  -----------------------  */
    
    // Copy Contructor
    Rectangle(const Rectangle& other);
    // Copy Assignment Operator
    Rectangle& operator = (const Rectangle& other);
    // Deconstructor
    ~Rectangle() { delete leftUp; leftUp = nullptr; }
    
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
Rectangle::Rectangle (const Rectangle& other):
Shape(other), width(other.width), height(other.height)
{
    if (other.leftUp != nullptr) {
        this->leftUp = new Point(*other.leftUp); // call copy ctr of Point
                                                 // immune for future Point changes
    }
    else {
        this->leftUp = nullptr;
    }
}

inline
Rectangle& Rectangle::operator = (const Rectangle& other)
{
    if (this == &other)
        return *this;
    
    this->Shape::operator=(other);
    
    this->width = other.w();
    this->height = other.h();
    
    if (this->leftUp != nullptr && other.leftUp != nullptr) {
        *this->leftUp = *other.leftUp;  // call copy op= of Class Point
    }
    else if (this->leftUp == nullptr && other.leftUp != nullptr) {
        this->leftUp = new Point(*other.leftUp);
    }
    else {
        delete leftUp;
    }
    
    return *this;
}

#endif