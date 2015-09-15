#include <iostream>
#include "rectangle.h"

using namespace std;

int main()
{
	Rectangle r1(1, 2, 3, 4); 
	Rectangle r2(5, 6, 7, 8);	
	
	Rectangle *r3 = new Rectangle;

	Rectangle r4 = r1;
	
	r4 = *r3; 
	
	delete r3;
}
