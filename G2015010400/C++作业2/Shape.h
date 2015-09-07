//
//  Shape.h
//  homework2
//
//  Created by Guti on 15/8/18.
//  Copyright (c) 2015年 Gutierrez. All rights reserved.
//

#ifndef homework2_Shape_h
#define homework2_Shape_h

class Shape
{
public:
    Shape(const int& no_ = 0) : no(no_) {}
    int getNo() const {return no;}
    virtual int getArea() = 0;
    virtual ~Shape(){}
    virtual void display() = 0;
private:
    int no;
};


#endif
