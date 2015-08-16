#include "rectangle.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    Rectangle* pRectangle1 = new Rectangle(1, 1, 1, 0, 0);
	Rectangle rectangle2(2,1,2,3);
	rectangle2.set_no(2);
	rectangle2.set_leftUP(Point(3,3));
	Rectangle rectangle3 = rectangle2;
	rectangle3.set_no(3);
	cout << *pRectangle1 << endl;
	cout << rectangle2 << endl;
	cout << rectangle3 << endl;
	pRectangle1->~Rectangle();
	delete pRectangle1;
	system("pause");
	return 0;
}