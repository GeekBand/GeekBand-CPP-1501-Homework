#include <iostream>
#include "rectangle.h"

using namespace std;

int main()
{
    Rectangle rect1(100, 100, 0, 0);
    cout << "rect1: " << rect1 << endl;

    Rectangle rect2(200, 150, 1, 2);
    cout << "rect2: "<< rect2 << endl;

    rect1 = rect2; // 拷贝赋值调用

    Rectangle rect3(rect2);  // 拷贝构造调用
    cout << "rect3: "<< rect3 << endl;

    Rectangle rect4 = rect1; // 拷贝构造调用
    cout << "rect4: "<< rect4 << endl;

    return 0;
}

/*
Output:
rect1: leftUp = (0,0), width = 100, height = 100.
rect2: leftUp = (1,2), width = 200, height = 150.
rect3: leftUp = (1,2), width = 200, height = 150.
rect4: leftUp = (1,2), width = 200, height = 150.
*/
