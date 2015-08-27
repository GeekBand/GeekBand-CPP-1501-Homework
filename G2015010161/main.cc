#include <iostream>
#include "rectangle.h"
using namespace std;

int main()
{
    Rectangle r1(1, 2, 3, 4);
    cout << r1;
    Rectangle r2 = r1;
    cout << r2;
    Rectangle r3(5, 6, 7, 8);
    cout << r3;
    Rectangle r4 = r3;
    cout << r4;

    r4 = r1;
    cout << r4;
}
