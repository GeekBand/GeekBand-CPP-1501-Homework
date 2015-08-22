#include "Rectangle.h"

Rectangle::Rectangle() : width(0), height(0), leftUp(new Point(0, 0))
{
    //ctor
}

Rectangle::~Rectangle()
{
    //dtor
    delete leftUp;
}

Rectangle::Rectangle(int width, int height, int x, int y) : width(width), height(height), leftUp(new Point(x, y))
{

}

Rectangle::Rectangle(const Rectangle& other) : width(other.width), height(other.height), leftUp(new Point(*(other.leftUp)))
{
    //copy ctor
}

Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    //assignment operator
    this->width = rhs.width;
    this->height = rhs.height;

    delete leftUp;
    leftUp = new Point(*(rhs.leftUp));

    return *this;
}

int Rectangle::get_width()
{
    return this->width;
}

int Rectangle::get_height()
{
    return this->height;
}

Point Rectangle::get_Point()
{
    return *(this->leftUp);
}
