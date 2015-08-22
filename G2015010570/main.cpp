#include "Rectangle.h"
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	Shape* s = new Rectangle(50, 50, 30, 30, 1);
	cout << "no=" << s->getNo() << endl;

	Rectangle* r = dynamic_cast<Rectangle*>(s);
	cout << "address of s=" << s << endl;
	cout << "address of r=" << r << endl;
	cout << "width of r=" << r->getWidth() << endl;
	cout << "height or r=" << r->getHeight() << endl;
	cout << "x or r=" << r->getX() << endl;
	cout << "y or r=" << r->getY() << endl;

	cout << endl;

	Rectangle r2 = *r;
	cout << "address of r2=" << &r2 << endl;
	cout << "width of r2=" << r2.getWidth() << endl;
	cout << "height of r2=" << r2.getHeight() << endl;
	cout << "x of r2=" << r2.getX() << endl;
	cout << "y of r2=" << r2.getY() << endl;

	cout << endl;

	Rectangle* r3 = new Rectangle(*r);
	cout << "address of r3=" << r3 << endl;
	cout << "width of r3=" << r3->getWidth() << endl;
	cout << "weight of r3=" << r3->getHeight() << endl;
	cout << "x of r3=" << r3->getX() << endl;
	cout << "y of r3=" << r3->getY() << endl;
	delete s;
	delete r3;
}

