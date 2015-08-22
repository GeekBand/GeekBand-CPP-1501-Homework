/*************************************************************************
	> File Name: main.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: 2015年08月27日 星期四 08时57分00秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include "rectangle.h"
#include "circle.h"
#include "shape.h"

using namespace std;

void create_rec_cir(shape* be[])
{
    srand(time(NULL));
    for(int i = 0; i < 20; ++i)
    {
        if(i < 10)
        {//create 10 rect
            int width = rand()%10;
            int height = rand()%10;
            int x = rand()%10;
            int y = rand()%10;
            width = width > 1 ? width : 1;
            height = height > 1 ? height : 1;
            x = x > 1 ? x : 1;
            y = y > 1 ? y : 1;
            be[i] = new Rectangle(width, height, x, y);
            be[i]->setNo(i);            
            
        }
        else
        {
            int radius = rand()%10;
            int x = rand()%10;
            int y = rand()%10;
            radius = radius > 1 ? radius : 1;
            x = x > 1 ? x : 1;
            y = y > 1 ? y : 1;
            be[i] = new Circle(radius, x, y);
            be[i]->setNo(i);
        }
    }
}

void print(shape* be[])
{
    for(int i = 0; i < 20; ++i)
    {
        if(i < 10)
        {
            cout << "width:" << ((Rectangle*)be[i])->getWidth() << endl;

        }
        else
        {
            cout << "radius:" << ((Circle*)be[i])->getRadius() << endl;
        }
    }
}

void select_leg_shape(shape* sp_before[], shape* sp_after[], int* n)
{
    int j = 0;
    for(int i = 0; i < 20; ++i)
    {
        if(sp_before[i]->getArea() >= 50)
        {
            sp_after[j++] = sp_before[i];
        }

    }
    *n = j;
}

void test_select(shape* sp_after[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        if(sp_after[i]->getNo() < 10)
        {
            cout << "rect area:" <<((Rectangle*)sp_after[i])->getArea() <<endl;
        }
        else
        {
            cout << "circle area:" << ((Circle*)sp_after[i])->getArea() << endl;
        }
    }
}

int main()
{
    shape* sp_before[20], * sp_after[20];
    int n;
    create_rec_cir(sp_before);
   // print(sp_before);
    select_leg_shape(sp_before, sp_after, &n);
    test_select(sp_after, n);

    return 0;
}
