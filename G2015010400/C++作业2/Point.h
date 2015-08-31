//
//  Point.h
//  homework2
//
//  Created by Guti on 15/8/18.
//  Copyright (c) 2015年 Gutierrez. All rights reserved.
//

#ifndef homework2_Point_h
#define homework2_Point_h

#include <iostream>

using namespace std;

class Point
{
public:
    Point(const int& x_ = 0, const int& y_ = 0) : x(x_), y(y_) {}
    friend ostream& operator << (ostream& os, const Point& unit);
private:
    int x;
    int y;
};

ostream& operator << (ostream& os, const Point& unit)
{
    os << "(" << unit.x <<"," << unit.y << ")";
    return os;
}

#endif
