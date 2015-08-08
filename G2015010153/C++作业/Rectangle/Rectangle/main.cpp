#include <iostream>
#include "rectangle.h"

using namespace std;
using namespace shape;

int main(void) {
	Rectangle rtl = Rectangle(100, 100, 1, 1);
	cout << "rtl : " << rtl << endl;	

	Rectangle rtl1 = Rectangle(100, 200, 2, 3);
	cout << "rtl1 : " << rtl1 << endl;	

	Rectangle rtl2 = rtl1;
	cout << "rtl2 : " << rtl2 << endl;	

	Rectangle rtl3 = Rectangle(rtl1);
	cout << "rtl3 : " << rtl3 << endl;	

	rtl3 = rtl;
	cout << "rtl3 : " << rtl3 << endl;	

	getchar();
	return 0;
}