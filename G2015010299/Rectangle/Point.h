#ifndef __POINT__
#define __POINT__

class Point
{
    int x;
    int y;

public:
    Point(int x, int y): x(x), y(y) {}
    Point(const Point& other): x(other.x), y(other.y) {}
};

#endif

