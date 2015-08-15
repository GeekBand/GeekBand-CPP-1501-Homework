#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <cstddef>

class Shape
{
    int no;
};
class Point
{
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}
};
class Rectangle : public Shape
{
    int width;
    int height;
    Point * leftUp;
public:
    Rectangle(int width, int height, int x, int y);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle();
};

inline Rectangle::Rectangle(int width, int height, int x, int y)
    : width(width), height(height) {
    leftUp = new Point(x, y);
}

inline Rectangle::Rectangle(const Rectangle& other)
    : Shape(other), width(other.width), height(other.height), leftUp(NULL) {
    if (other.leftUp) {
        leftUp = new Point(*other.leftUp);
    }
}

inline Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this == &other) return *this;

    Shape::operator=(other);
    width = other.width;
    height = other.height;

    if (other.leftUp) {
        if (leftUp) {
            *leftUp = *other.leftUp;
        } else {
            leftUp = new Point(*other.leftUp);
        }
    } else {
        delete leftUp;
        leftUp = NULL;
    }

    return *this;
}

inline Rectangle::~Rectangle() {
    delete leftUp;
    leftUp = NULL;
}

#endif // _RECTANGLE_H_

