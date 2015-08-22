#include <iostream>
#include "Rectangle.h"

int main()
{
	Rectangle r1(10, 20, 30, 40);
	Rectangle r2(r1);
	Rectangle r3 = r2;

	Rectangle r4(4, 3, 2, 1);
	r2 = r4;

	r1 = r1;

	r1.printData();
	r2.printData();
	r3.printData();
	r4.printData();

	return 0;
}