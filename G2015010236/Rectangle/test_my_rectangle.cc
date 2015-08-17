#include "rectangle.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    Rectangle* pRectangle1 = new Rectangle(1, 1, 1, 0, 1);
	Rectangle rectangle2(2,1,2,3,2);
	Rectangle rectangle3 = rectangle2;
	cout << *pRectangle1 << endl;
	cout << rectangle2 << endl;
	cout << rectangle3 << endl;
	pRectangle1->~Rectangle();
	delete pRectangle1;
	system("pause");
	return 0;
}