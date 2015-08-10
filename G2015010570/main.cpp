#include "Rectangle.h"
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	Shape* s = new Rectangle(50, 50, 30, 30, 1);
	cout << "no=" << s->getNo() << endl;

	Rectangle* r = dynamic_cast<Rectangle*>(s);
	cout<<"address of s="<<s<<endl;
	cout<<"address of r="<<r<<endl;
	cout << "width=" << r->getWidth() << endl;
	cout << "weight=" << r->getHeight() << endl;
	cout << "x=" << r->getX() << endl;
	cout << "y=" << r->getY() << endl;

	cout<<endl;

	Rectangle r2 = *r;
	cout<<"address of r2="<<&r2<<endl;
	cout << "r2 width=" << r2.getWidth() << endl;
	cout << "r2 weight=" << r2.getHeight() << endl;
	cout << "r2 x=" << r2.getX() << endl;
	cout << "r2 y=" << r2.getY() << endl;

	cout<<endl;

	Rectangle* r3 = new Rectangle(*r);
	cout<<"address of r3="<<r3<<endl;
	cout << "r3 width=" << r3->getWidth() << endl;
	cout << "r3 weight=" << r3->getHeight() << endl;
	cout << "r3 x=" << r3->getX() << endl;
	cout << "r3 y=" << r3->getY() << endl;
	delete s;
	delete r3;
}

