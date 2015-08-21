#include <iostream>
#include "Shape.h"

using namespace std;

int main() {
    Rectangle r1(5, 10, 1, 2);

    Rectangle r2(r1);

    Rectangle r3 = r1;
    r2 = r3;

    cout << "Hello, World!" << endl;
    return 0;
}