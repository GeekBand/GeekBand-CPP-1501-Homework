#ifndef __POINT_H_
#define __POINT_H_

class Point
{
    int x;
    int y;
public:
    Point(int _x, int _y)
    :x(_x), y(_y)
    {}

    int getX() const { return x; }
    int getY() const { return y; }
};



#endif
