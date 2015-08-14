#include <iostream>

#include "Rectangle.h"

using namespace std;

int main()
{
    Rectangle rect1 = Rectangle(10, 12, 3, 4);
    Rectangle rect2 = Rectangle(rect1);
    Rectangle rect3 = rect1;

    cout << " rect1.width: " << rect1.get_width() << " rect1.height: " << rect1.get_height() << endl;
    cout << " rect1. point x: " << rect1.get_Point().get_x() << " rect1. point y:  " << rect1.get_Point().get_y() << endl;
    cout << " rect2.width: " << rect2.get_width() << " rect2.height: " << rect2.get_height() << endl;
    cout << " rect2. point x: " << rect2.get_Point().get_x() << " rect2. point y:  " << rect2.get_Point().get_y() << endl;
    cout << " rect3.width: " << rect3.get_width() << " rect3.height: " << rect3.get_height() << endl;
    cout << " rect3. point x: " << rect3.get_Point().get_x() << " rect3. point y:  " << rect3.get_Point().get_y() << endl;
    return 0;
}
