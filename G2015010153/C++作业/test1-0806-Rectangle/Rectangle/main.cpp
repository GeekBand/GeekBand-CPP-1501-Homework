#include <iostream>
#include "rectangle.h"

using namespace std;
using namespace Geekband;

int main(void) {
	Rectangle rtl1 = Rectangle(100, 100, 1, 1, 0);
	cout << "rtl1 : " << rtl1 << endl;	

	Rectangle rtl2 = Rectangle(rtl1);
	cout << "rtl2 : " << rtl2 << endl;	

	rtl1.set_leftup(NULL);
	cout << "rtl1 : " << rtl1 << endl;	

	rtl2 = rtl1;
	cout << "rtl2 : " << rtl2 << endl;	

	rtl2 = rtl2;
	cout << "rtl2 : " << rtl2 << endl;	

	getchar();
	return 0;
}