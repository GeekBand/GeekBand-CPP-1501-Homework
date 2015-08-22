#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point.h"


class Rectangle : public Shape
{
    public:
        Rectangle();
        ~Rectangle();
        Rectangle(int width, int height, int x, int y);
        Rectangle(const Rectangle& other);
        Rectangle& operator=(const Rectangle& other);

        int get_width();
        int get_height();
        Point get_Point();
    private:
        int width;
        int height;

        Point* leftUp;
};

#endif // RECTANGLE_H
