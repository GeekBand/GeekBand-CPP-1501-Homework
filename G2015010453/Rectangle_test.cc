#include "Rectangle.h"

#include <iostream>
using namespace std;

int main(void)
{
	Rectangle rect1;
	cout << rect1 << endl;

	Rectangle rect2(1, 2);
	cout << rect2 << endl;

	Rectangle rect3(rect2);
	cout << rect3 << endl;

	rect3 = rect1;
	cout << rect3 << endl;

	Rectangle *rect4 = new Rectangle(1, 2, 3);
	cout << *rect4 << endl;
	delete rect4;

	return 0;
}
