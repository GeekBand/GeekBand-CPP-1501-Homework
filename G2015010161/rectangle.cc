#include <iostream>
#include "rectangle.h"
using std::ostream;
using std::endl;

Rectangle::Rectangle(int w, int h, int x, int y):
    width(w), height(h)
{
    leftUp = new Point(x, y);
}

Rectangle::Rectangle(const Rectangle &rec):
    width(rec.width), height(rec.height)
{
    leftUp = new Point(rec.leftUp->getX(), rec.leftUp->getY());
}

Rectangle &Rectangle::operator=(const Rectangle &rec)
{
    if (this == &rec)
        return *this;

    this->width = rec.width;
    this->height = rec.height;
    this->leftUp->updatePosition(rec.leftUp->getX(), rec.leftUp->getY());

    return *this;
}

Rectangle::~Rectangle()
{
    delete leftUp;
}

ostream &operator<<(ostream &os, const Rectangle &rec)
{
    os << "rectangle width is " << rec.width << " " << rec.height << endl;
    os << "rectangle position is " << rec.leftUp->getX() << " " << rec.leftUp->getY() << endl;
    return os;
}
