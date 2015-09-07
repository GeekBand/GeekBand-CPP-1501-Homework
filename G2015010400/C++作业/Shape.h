<<<<<<< HEAD
//
//  Shape.h
//  G2015010400
//
//  Created by Guti on 15/8/9.
//  Copyright (c) 2015年 Guti. All rights reserved.
//

#ifndef G2015010400_Shape_h
#define G2015010400_Shape_h

class Shape{
public:
    Shape(){
        no = count++;
    }
    int getno() const { return no;}
    virtual ~Shape(){ count--; }
    
    static int count;
    
private:
    int no;
    
};

int Shape::count = 1;

#endif

