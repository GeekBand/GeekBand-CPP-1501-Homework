#include <iostream>

#include "Rectangle.h"

using namespace std;
int main()
{
	Rectangle rectangle1(1,2);
	Rectangle rectangle2(rectangle1);
	rectangle1 = rectangle1;
	rectangle1 = rectangle2;

	cout << "End of this test"<<endl;
	return 0;
}
