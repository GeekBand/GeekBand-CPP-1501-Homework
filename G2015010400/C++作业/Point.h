<<<<<<< HEAD
//
//  Point.h
//  G2015010400
//
//  Created by Guti on 15/8/9.
//  Copyright (c) 2015年 Guti. All rights reserved.
//

#ifndef G2015010400_Point_h
#define G2015010400_Point_h

class Point{
public:
    Point(int x_ = 0, int y_ = 0): x(x_), y(y_) {}
    friend int getx(const Point&);
    friend int gety(const Point&);
private:
    int x;
    int y;
};

inline int getx(const Point& point){
    return point.x;
}
inline int gety(const Point& point){
    return point.y;
}

#endif

