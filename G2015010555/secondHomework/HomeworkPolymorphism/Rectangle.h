//
//  Rectangle.h
//  HomeworkPolymorphism
//
//  Created by 杨益榜 on 15/8/22.
//  Copyright (c) 2015年 Yvan. All rights reserved.
//

#ifndef __HomeworkPolymorphism__Rectangle__
#define __HomeworkPolymorphism__Rectangle__

#include "Point.h"
#include "Shape.h"

class Rectangle:public Shape
{
    int width;
    int height;
    
    Point leftUp;
    
public:
    Rectangle(int no = 0, int width = 0, int height = 0, int x = 0, int y = 0);
    ~Rectangle();
    
    virtual int getArea() const override;
    
    virtual void print() const override;
    
};

#endif /* defined(__HomeworkPolymorphism__Rectangle__) */
