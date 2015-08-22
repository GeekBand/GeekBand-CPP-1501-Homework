//
//  Rectangle.h
//  G2015010400
//
//  Created by Guti on 15/8/9.
//  Copyright (c) 2015年 Guti. All rights reserved.
//

#ifndef G2015010400_Rectangle_h
#define G2015010400_Rectangle_h

#include <iostream>

#include "Shape.h"
#include "Point.h"

using namespace std;

class Rectangle: public Shape{
public:
    Rectangle(int width_ = 0, int height_ = 0, int x_ = 0 , int y_ = 0): width(width_), height(height_), leftup(new Point(x_, y_)) {}
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle();
    friend ostream& operator<<(ostream& os, const Rectangle& other);
private:
    int width;
    int height;
    Point* leftup;
};

inline Rectangle::Rectangle(const Rectangle& other)
{
    width = other.width;
    height = other.height;
    leftup = new Point(getx(*(other.leftup)), gety(*(other.leftup)));
}
inline Rectangle& Rectangle::operator=(const Rectangle& other)
{
    width = other.width;
    height = other.height;
    leftup = new Point(getx(*(other.leftup)), gety(*(other.leftup)));
    return *this;
}
inline Rectangle::~Rectangle()
{
    delete leftup;
}

inline ostream& operator<<(ostream& os, const Rectangle& other)
{
    os<<"Shape No."<<other.getno()<<" ("<<other.width<<","<<other.height<<")"<<getx(*(other.leftup))<<" "<<gety(*(other.leftup))<<endl;
    return os;
}
#endif
