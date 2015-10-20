#ifndef POINT_H
#define POINT_H

#include <iostream>

using std::ostream;

class Point
{
public:
    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    Point& operator = (const Point& other);
    
    int getx() const {return x;}
    int gety() const {return y;}
private:
    int x,y;
};

Point& Point::operator = (const Point& other)
{
    x = other.getx();
    y = other.gety();
    return *this;
}

ostream& operator << (ostream& os, const Point& point)
{
    os << "(" << point.getx() << "," << point.gety() << ")";
    return os;
}



#endif