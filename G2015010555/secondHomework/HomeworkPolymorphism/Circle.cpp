//
//  Circle.cpp
//  HomeworkPolymorphism
//
//  Created by 杨益榜 on 15/8/22.
//  Copyright (c) 2015年 Yvan. All rights reserved.
//

#include <iostream>
#include "Circle.h"

#define PI 3.14

Circle::Circle(int no, int radius, int x, int y):radius(radius),center(x, y), Shape(no)
{}

Circle::~Circle() {}

int Circle::getArea() const {
    return PI * radius * radius;
}

void Circle::print() const
{
    Shape::print();
    std::cout<< " circle area: " << getArea() << std::endl;
}

