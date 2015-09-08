//
//  main.cpp
//  1
//
//  Created by 何彬 on 15/8/27.
//  Copyright (c) 2015年 何彬. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "shape.h"
using namespace std;

int getRandomValue()
{
    return (1 + rand() % 10);
}

void randomArray(Shape** shape_array)
{
    for (int i = 0; i <= 9; ++i) {
        shape_array[i] = new Rectangle(getRandomValue(), getRandomValue(), getRandomValue(), getRandomValue(), i);
    }
    for (int i = 10; i<=19; ++i) {
        shape_array[i] = new Circle(getRandomValue(), getRandomValue(),getRandomValue(), i);
    }
}

int selectShape(Shape** shape_array, Shape ***pshape_array2, int* pnum)
{
    int num = 1;
    Shape** shape_array2 = (Shape**)malloc(num);
    for (int i = 0; i < 20; ++i) {
        if (shape_array[i]->getArea() >= 50) {
            Shape** shape_array2 = (Shape**)realloc(*shape_array, num);
            shape_array2[num-1] = shape_array[i];
            num++;
        }
    }
    *pnum = num-1;
    *pshape_array2 = shape_array2;
    shape_array2 = nullptr;
}

int main()
{
    srand((unsigned)time(NULL));
    Shape** shape_array = new Shape*[20];
    randomArray(shape_array);
    Shape** shape_array2 = nullptr;
    int num = 0;
    selectShape(shape_array, &shape_array2, &num);
    cout << "Area larger than 50: " << endl;
    for (int i = 0; i < num; ++i) {
        shape_array2[i]->print();
    }
    for (int i = 0; i < 20; ++i) {
        delete shape_array[i];
        shape_array[i] = nullptr;
    }
    delete[] shape_array;
    for (int i = 0; i < num; ++i) {
        shape_array2[i] = nullptr;
    }
    delete[] shape_array2;
    shape_array2 = nullptr;
    return 0;
}