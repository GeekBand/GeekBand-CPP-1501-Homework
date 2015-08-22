//
//  main.cpp
//  G2015010400
//
//  Created by Guti on 15/8/9.
//  Copyright (c) 2015年 Guti. All rights reserved.
//

#include <iostream>

#include "Shape.h"
#include "Rectangle.h"
#include "Point.h"

using namespace std;

void display(const Rectangle& it)
{
    
}

int main() {
    
    Rectangle r1;
    cout<<r1;
    Rectangle r2(20, 20, 10, 10);
    cout<<r2;
    Rectangle r3(r2);
    r1 = r3;
    cout<<r1<<r2<<r3;
    return 0;
}
