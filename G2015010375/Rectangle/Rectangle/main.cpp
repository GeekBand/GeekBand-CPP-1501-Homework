#include <iostream>

#include "Rectangle.h"

using namespace std;

void main()
{
	Rectangle* rc1 = new Rectangle(1, 1, 2, 2);
	Rectangle rc2(*rc1);
	Point p(3, 3);

	rc2.setPoint(p);
	cout << rc2.getPoint().getX() << "|" << rc1->getPoint().getX() << "|" << &rc1 << "|" << &rc2;

	rc2 = *rc1;
	cout << rc2.getPoint().getX();
}