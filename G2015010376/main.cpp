#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {

    Rectangle r1(15, 80, 90, 90);
    cout << r1.left_up()->x() << endl;
    cout << r1.left_up()->y() << endl;
    cout << r1.width() << endl;
    cout << r1.height() << endl;

    return 0;
}