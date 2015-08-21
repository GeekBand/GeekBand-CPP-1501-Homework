#include <iostream>
#include <random>
#include "Rectangle.h"
using namespace std;
#define RAND10() (rd() % 10 + 1)

int main()
{
	Shape* shape[20];
	std::random_device rd;
	for (int i = 0; i < 20; i++) {
		if (i < 10) {
			shape[i] = new Rectangle(RAND10(), RAND10(), RAND10(), RAND10());
		}
		else {
			shape[i] = new Circle(RAND10(), RAND10(), RAND10());
		}
		shape[i]->setNo(i);
	}
	
	int count = 0;
	int delNum = 0;
	for (int i = 0; i < 20; i++) {
		if (shape[i]->getArea() < 50) {
			delNum++;
			delete shape[i];
		}
		else{
			shape[count] = shape[i];
			count++;
		}
	}

	for (int i = 0; i < count; i++) {
		cout << "Area:" << shape[i]->getArea() << endl;
	}
	return 0;
}