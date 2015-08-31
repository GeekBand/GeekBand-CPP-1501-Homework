#include "shape.h"
#include "point.h"
#include "rectangle.h"
#include <iostream>

using namespace std;

int main() {
    Rectangle r1(4, 3, 0, 0);
    Rectangle r2(6, 2, 3, 2);
    Rectangle r3(-6, -2, 3, 2);

    Rectangle r4(r2);

    r3.setNo(1);
    r4 = r3;

    cout << "r1:width=" << r1.getWidth() << ";height=" << r1.getHeight() << ";x=" << r1.getLeftUp().getX()
        << ";y=" << r1.getLeftUp().getY() << endl;
    cout << "r2:width=" << r2.getWidth() << ";height=" << r2.getHeight() << ";x=" << r2.getLeftUp().getX()
        << ";y=" << r2.getLeftUp().getY() << ";no=" << r2.getNo() << endl;
    cout << "r3:width=" << r3.getWidth() << ";height=" << r3.getHeight() << ";x=" << r3.getLeftUp().getX()
        << ";y=" << r3.getLeftUp().getY() << ";no=" << r3.getNo() << endl;
    cout << "r4:width=" << r4.getWidth() << ";height=" << r4.getHeight() << ";x=" << r4.getLeftUp().getX()
        << ";y=" << r4.getLeftUp().getY() << ";no=" << r4.getNo() << endl;

    return 0;
}