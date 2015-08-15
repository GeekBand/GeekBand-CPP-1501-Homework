#include "rectangle.cpp"
#include <iostream>

using namespace std;

int main()
{
	Rectangle rectangle(1,2,1,2);
	Rectangle rectangle1 = rectangle;
	cout<<rectangle<<endl;
	cout<<rectangle1<<endl;
	Rectangle rectangle2(1,2,3,4);
	rectangle2 = rectangle1;
	cout<<rectangle2<<endl;
	return 0;
}
