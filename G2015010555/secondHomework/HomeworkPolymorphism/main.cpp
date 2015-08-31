//
//  main.cpp
//  HomeworkPolymorphism
//
//  Created by 杨益榜 on 15/8/22.
//  Copyright (c) 2015年 Yvan. All rights reserved.
//

#include <iostream>
#include <cstdlib>// contains prototypes for functions srand and rand
#include <ctime>// contains prototype for function time
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

int main(int argc, const char * argv[]) {
    
    // randomize random number generator using current time
    srand(static_cast<unsigned int>(time(0)));
    
    Shape* rectShapes[10];
    Shape* circleShapes[10];
    
    unsigned int counter = 0;
    unsigned int newRectCount = 0;
    unsigned int newCircleCount = 0;
    
    while (counter < 10) {
        
        rectShapes[counter] = new Rectangle(counter + 1
                                            , 1 + rand() % 10
                                            , 1 + rand() % 10
                                            , 1 + rand() % 10
                                            , 1 + rand() % 10);
        
        if (rectShapes[counter]->getArea() >= 50) {
            newRectCount++;
        }
        
        circleShapes[counter] = new Circle(counter + 1
                                           , 1 + rand() % 10
                                           , 1 + rand() % 10
                                           , 1 + rand() % 10);
        
        if (circleShapes[counter]->getArea() >= 50) {
            newCircleCount++;
        }
        
        counter++;
    }
    
    counter = 0;
    Shape* newRectShapes[newRectCount];
    newRectCount = 0;
    Shape* newCircleShapes[newCircleCount];
    newCircleCount = 0;
    
    while (counter < 10) {
        if (rectShapes[counter]->getArea() >= 50) {
            newRectShapes[newRectCount++] = rectShapes[counter];
        } else {
            delete rectShapes[counter];
        }
        
        if (circleShapes[counter]->getArea() >= 50) {
            newCircleShapes[newCircleCount++] = circleShapes[counter];
        } else {
            delete circleShapes[counter];
        }
        
        counter++;
    }

    for (unsigned int i = 0; i < newRectCount; i++) {
        newRectShapes[i]->print();
    }
  
    for (unsigned int i = 0; i < newRectCount; i++) {
        delete newRectShapes[i];
    }
    
    std::cout << "===================" << std::endl;
    
    for (unsigned int i = 0; i < newCircleCount; i++) {
        newCircleShapes[i]->print();
    }
    
    for (unsigned int i = 0; i < newCircleCount; i++) {
        delete newCircleShapes[i];
    }
    
    return 0;
}
