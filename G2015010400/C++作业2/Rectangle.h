//
//  Rectangle.h
//  homework2
//
//  Created by Guti on 15/8/18.
//  Copyright (c) 2015年 Gutierrez. All rights reserved.
//

#ifndef homework2_Rectangle_h
#define homework2_Rectangle_h

#include <iostream>

#include "Shape.h"
#include "Point.h"

using namespace std;

class Rectangle : public Shape
{
public:
    Rectangle(const int& width_ = 0, const int& height_ = 0, const Point& leftup_ = Point(), const int& no = 0) : width(width_), height(height_), leftup(leftup_), Shape(no) {}
    int getArea();
    void display();
private:
    int width;
    int height;
    Point leftup;
};

inline int Rectangle::getArea()
{
    if (width != 0 && height != 0) {
        return width * height;
    }
    return 0;
}

void Rectangle::display()
{
    std::cout << getNo() << ":" << width << " " << height << leftup << endl;
    std::cout << "Area:" << getArea() << endl;
    
}


#endif
