//
//  Circle.h
//  HomeworkPolymorphism
//
//  Created by 杨益榜 on 15/8/22.
//  Copyright (c) 2015年 Yvan. All rights reserved.
//

#ifndef __HomeworkPolymorphism__Circle__
#define __HomeworkPolymorphism__Circle__

#include "Point.h"
#include "Shape.h"

class Circle: public Shape
{
    Point center;
    int radius;
    
public:

    Circle(int no = 0, int radius = 0, int x = 0, int y = 0);
    ~Circle();
    
    virtual int getArea() const override;
    
    virtual void print() const override;
};

#endif /* defined(__HomeworkPolymorphism__Circle__) */
