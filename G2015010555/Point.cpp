#include "Point.h"

Point::Point() : x(0), y(0)
{
    //ctor
}

Point::Point(int x, int y) : x(x), y(y)
{
    //ctor
}

int Point::get_x(){
    return this->x;
}

int Point::get_y(){
    return this->y;
}
