//
//  Shape.cpp
//  HomeworkPolymorphism
//
//  Created by 杨益榜 on 15/8/22.
//  Copyright (c) 2015年 Yvan. All rights reserved.
//

#include <iostream>
#include "Shape.h"

Shape::Shape(int no):no(no) {}

Shape::~Shape() { }

void Shape::print() const {
    std::cout<< "no: " << no << std::endl;
}

