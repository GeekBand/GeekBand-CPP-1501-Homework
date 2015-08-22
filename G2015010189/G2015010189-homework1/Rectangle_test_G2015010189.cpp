// homework1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	Point pa(4,5);
	//cout << "a: " << pa.get_x() << "," << pa.get_y() << endl;
	Point pb = pa;
	//cout << "b: " << pb.get_x() << "," << pb.get_y() << endl;
	Point pc(pa);
	cout << "c: " << pc.get_x() << "," << pc.get_y() << endl;
		
	Rectangle R1(3,4,5,6);
	cout << "R1 : " << R1 << endl;	
	Rectangle R2(7,8,9);
	cout << "R2 : " << R2 << endl;
	Rectangle R3(R1);
	cout << "R3 : " << R3 << endl;
	Rectangle R4 = R2;
	cout << "R4 : " << R4 << endl;
	R4 = R4;
	cout << "R4 : " << R4 << endl;	
	Rectangle R5;
	cout << "R5 : " << R5 << endl;
	system("pause");
	return 0;
}

