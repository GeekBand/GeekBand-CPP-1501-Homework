// cpphomework.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "rectangle.h"
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	Rectangle rect(100, 100, 0, 0);
	rect.PrintDetail();

	cout << "rect.GetHeigth() " << rect.GetHeight() << endl;
	cout << "rect.GetWidth() " << rect.GetWidth() << endl;
	cout << "rect.GetStarPoint() " << "x = " << rect.GetStartPoint().x << "   " << "y = " << rect.GetStartPoint().y << endl;

	cout << endl;
	rect.SetHeight(20);
	rect.SetWidth(30);

	Point pt(25, 25);
	rect.SetStartPoint(pt);
	rect.PrintDetail();

	return 0;
}

