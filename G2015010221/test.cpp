// Retangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Rectangle.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Rectangle r1(3, 68, 4, 5);
	r1.display();
	Rectangle r2(r1);
	r2.display();
	Rectangle r3 = r1;
	r3.display();
	return 0;
	
}

