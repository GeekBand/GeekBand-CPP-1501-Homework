//
//  main.cpp
//  homework2
//
//  Created by Guti on 15/8/17.
//  Copyright (c) 2015年 Gutierrez. All rights reserved.
//

#include <iostream>

#include "Shape.h"
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"



int main(int argc, const char * argv[]) {
    // insert code here...
    Shape* arrayShip[20];
    for (int i = 0; i < 10; i++) {
        arrayShip[i] = new Rectangle(rand()%11, rand()%11, Point(rand()%11, rand()%11), i + 1);
    }
    for (int i = 10; i < 20; i++) {
        arrayShip[i] = new Circle(rand()%11, Point(rand()%11, rand()%11), i + 1);
    }
    
    /*  test
    for (int i = 0; i < 20; i++) {
        (*arrayShip[i]).display();
    }
    */
    
    Shape* arraySubstract[20];
    Shape** str = arraySubstract;
    
    for (int i = 0 ; i < 20; i++) {
        if ((*arrayShip[i]).getArea() >= 50) {
            *str = arrayShip[i];
            str++;
        }
    }
    std::cout << std::endl;
    int count = str - arraySubstract;
    for (int i = 0; i < count; i++) {
        (*arraySubstract[i]).display();
    }
    return 0;
}
