//
//  Rectangle.cpp
//  HomeworkPolymorphism
//
//  Created by 杨益榜 on 15/8/22.
//  Copyright (c) 2015年 Yvan. All rights reserved.
//

#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
#include "Rectangle.h"

Rectangle::Rectangle(int no, int width, int height, int x, int y)
    :width(width),height(height), leftUp(x, y), Shape(no)
{

}

Rectangle::~Rectangle()
{}

int Rectangle::getArea() const {
    return width * height;
}

void Rectangle::print() const {
    Shape::print();
    std::cout<< " rectangle area: " << getArea() << std::endl;
}

