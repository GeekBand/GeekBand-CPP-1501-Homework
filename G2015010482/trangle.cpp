#include <iostream>
#include "trangle.h"
using namespace std;
int main()
{
	cout<<"hello world\n";
	Rectangle creator(8,8,8,8);
	cout<<"constructor test...\n"<<"width="<<creator.getWidth()<<" height="<<creator.getHeight();
	creator.printPoint();
	Rectangle copyConstructor(Rectangle(7,7,7,7));
	cout<<"copyConstructor test...\n"<<"width="<<copyConstructor.getWidth()<<" height="<<copyConstructor.getHeight();
	copyConstructor.printPoint();
	Rectangle *copyAssign = new Rectangle(1,1,1,1);
	*copyAssign = Rectangle(6,6,6,6);
	cout<<"copyAssign test...\n"<<"width="<<copyAssign->getWidth()<<" height="<<copyAssign->getHeight();
	copyAssign->printPoint();
	delete copyAssign;
	return 1;
}