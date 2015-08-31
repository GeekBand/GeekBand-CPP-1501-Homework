//
//  Shape.h
//  HomeworkPolymorphism
//
//  Created by 杨益榜 on 15/8/22.
//  Copyright (c) 2015年 Yvan. All rights reserved.
//

#ifndef __HomeworkPolymorphism__Shape__
#define __HomeworkPolymorphism__Shape__

class Shape
{
    int no;

public:
    Shape(int no = 0);
    virtual int getArea() const = 0;
    virtual ~Shape();
    
    virtual void print() const;
};

#endif /* defined(__HomeworkPolymorphism__Shape__) */
