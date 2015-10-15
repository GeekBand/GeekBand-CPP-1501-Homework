#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(int argc, char** argv) 
{
	Rectangle R1(1, 2, 3, 4);
	if ((R1.getW() == 1) && (R1.getH() == 2) && (R1.getPoint() != nullptr) && (R1.getPoint()->getX() == 3) && (R1.getPoint()->getY() == 4))
	{
		cout << "R1(1, 2, 3, 4) Create OK" << endl;
	}
	else
	{
		cout << "***R1(1, 2, 3, 4) Create Failed ***" << endl;
		system("pause");
	}

	Rectangle R2(R1);
	if ((R2.getW() == 1) && (R2.getH() == 2) && (R2.getPoint() != nullptr) && (R2.getPoint()->getX() == 3) && (R2.getPoint()->getY() == 4)
		&& (R2.getPoint() != R1.getPoint()) )
	{
		cout << "R2 Create OK" << endl;
	}
	else
	{
		cout << "***R2 Create Failed ***" << endl;
		system("pause");
	}

	Rectangle R3 = R2;
	if ((R3.getW() == 1) && (R3.getH() == 2) && (R3.getPoint() != nullptr) && (R3.getPoint()->getX() == 3) && (R3.getPoint()->getY() == 4)
		&& (R3.getPoint() != R2.getPoint()))
	{
		cout << "R3 Create OK" << endl;
	}
	else
	{
		cout << "***R3 Create Failed ***" << endl;
		system("pause");
	}

	return 0;
}