//
//  Circle.h
//  homework2
//
//  Created by Guti on 15/8/18.
//  Copyright (c) 2015年 Gutierrez. All rights reserved.
//

#ifndef homework2_Circle_h
#define homework2_Circle_h

#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
public:
    Circle(const int& radius_ = 0, const Point& center_ = Point(), const int& no_ = 0 ) : radius(radius_), center(center_), Shape(no_) {}
    int getArea();
    void display();
private:
    int radius;
    Point center;
};

inline int Circle::getArea()
{
    if (radius != 0) {
        return 3.141592653 * radius * radius;
    }
    return 0;
}

void Circle::display()
{
    std::cout << getNo() << ":" << radius << center << endl;
    std::cout << "Area:" << getArea() << endl;
}

#endif
