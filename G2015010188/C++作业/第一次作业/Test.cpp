#include "Shape.h"
#include <iostream>
using namespace std;

int main() {
	Rectangle rect1;
	cout << rect1;

	Rectangle rect2(40, 80);
	cout << rect2;

	Rectangle rect3(rect2);
	cout << rect3;

	rect1 = rect1;
	cout << rect1;

	rect1 = rect2;
	cout << rect1;

	Rectangle *pRect = nullptr;
	pRect = new Rectangle(rect3);
	cout << *pRect;
	getchar();
	return 0;
}