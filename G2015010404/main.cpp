#include <iostream>
#include "rectangle.h"
using namespace std;

int main()
{
    Rectangle rect1(2,2,1,1);
    Rectangle rect2(rect1);
    Rectangle rect3;
    Rectangle rect4 = rect3;

    rect2 = rect3;
    rect2 = rect1;
    rect4 = rect3;
    return 0;
}

