#include <iostream>

#include "rectangle.h"

using namespace std;

void TestCopyConstructor() {
    Rectangle a(1, 2, 3, 4);
    Rectangle b(a);
    if (!a.Equals(b)) {
        cerr << "Copy constructor test fail!" << endl;
    } else {
        cout << "Copy constructor test pass!" << endl;
    }
}

void TestCopyAssign() {
    Rectangle a(1, 2, 0, 0);
    Rectangle b(2, 3, 2, 1);
    a = b;
    if (!a.Equals(b)) {
        cerr << "Copy assign test fail!" << endl;
    } else {
        cout << "Copy assign test pass!" << endl;
    }
}

int main() {
    TestCopyConstructor();
    TestCopyAssign();
    return 0;
}

