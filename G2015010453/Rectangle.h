#ifndef RECTANGLE_H
#define RECTANGLE_H

class Shape
{
    int no;
public:
    virtual ~Shape() {}
};

class Point
{
public:
    Point(int x = 0, int y = 0) :x(x), y(y) {}
    Point(const Point& p) :x(p.getX()), y(p.getY()) {} 

    int getX() const { return x; }
    int getY() const { return y; }

private:   
    int x;
    int y;
};

class Rectangle : public Shape
{
public:    
    Rectangle(int width = 0, int height = 0, int x = 0, int y = 0)
        :width(width), height(height), leftUp(new Point(x, y)) {}
    Rectangle(const Rectangle& other);
    Rectangle& operator = (const Rectangle& other);
    virtual ~Rectangle();

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    Point* getLeftUp() const { return leftUp; } 

private:
    int width;
    int height;

    Point *leftUp;
};

inline
Rectangle::Rectangle(const Rectangle& other)
{
    width = other.getWidth();
    height = other.getHeight();

    leftUp = new Point(*other.getLeftUp());
}

inline
Rectangle::~Rectangle()
{
    delete leftUp;
}

inline Rectangle& 
Rectangle::operator = (const Rectangle& other)
{
    if (this == &other) {
        return *this;
    }

    this->width = other.getWidth();
    this->height = other.getHeight();

    delete leftUp;
    leftUp = new Point(*other.getLeftUp());

    return *this;
}

#include <iostream>
using namespace std;

ostream&
operator << (ostream& os, const Rectangle& rect)
{
    return os << "rectangle[" << rect.getWidth() << ", " << rect.getHeight()
                << ", (" << rect.getLeftUp()->getX() << "," << rect.getLeftUp()->getY() << ")]";
}

#endif //RECTANGLE_H