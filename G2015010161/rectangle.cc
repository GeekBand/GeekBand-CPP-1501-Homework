#include <iostream>
#include "rectangle.h"
using std::ostream;
using std::endl;

Rectangle::Rectangle(int w, int h, int x, int y):
    width(w), height(h), leftUp(new Point(x, y))
{
}

Rectangle::Rectangle(const Rectangle &rec):
    Shape(rec), width(rec.width), height(rec.height)
{
    if (rec.leftUp != NULL)
        leftUp = new Point(*rec.leftUp);
    else
        leftUp = NULL;
}

Rectangle &Rectangle::operator=(const Rectangle &rec)
{
    if (this == &rec)
        return *this;

    Shape::operator=(rec);
    this->width = rec.width;
    this->height = rec.height;
    if (rec.leftUp != NULL) {
        if (leftUp != NULL)
            *leftUp = *rec.leftUp;
        else
            leftUp = new Point(*rec.leftUp);
    }
    else
        leftUp = NULL;

    return *this;
}

Rectangle::~Rectangle()
{
    delete leftUp;
    leftUp = NULL;
}

ostream &operator<<(ostream &os, const Rectangle &rec)
{
    os << "rectangle width is " << rec.width << " " << rec.height << endl;
    os << "rectangle position is " << rec.leftUp->getX() << " " << rec.leftUp->getY() << endl;
    return os;
}
