#include <iostream>
#include <random>
#include "Rectangle.h"
using namespace std;
#define RAND10() (rd() % 10 + 1)
#define SHAPE_NUM 20

void shapeInit(Shape** shape, int size)
{
	std::random_device rd;
	for (int i = 0; i < size; i++) {
		if (i < 10) {
			shape[i] = new Rectangle(RAND10(), RAND10(), RAND10(), RAND10());
		}
		else {
			shape[i] = new Circle(RAND10(), RAND10(), RAND10());
		}
		shape[i]->setNo(i);
	}
}

Shape** selectArea50(Shape** shape, int size, int& count)
{
	Shape** shapeArea50 =NULL;
	int num = 0;
	int delNum = 0;
	for (int i = 0; i < size; i++) {
		if (shape[i]->getArea() < 50) {
			delNum++;
			delete shape[i];
		}
		else {
			shape[num] = shape[i];
			num++;
		}
	}
	if (num == 0) {
		return NULL;
	}
	shapeArea50 = new Shape*[num];
	for (int i = 0; i < num; i++) {
		shapeArea50[i] = shape[i];
		cout <<"size:"<<shapeArea50[i]->getArea() << endl;
	}
	count = num;
	return shapeArea50;
}

void shapeDel(Shape** shape, int size)
{
	for (int i = 0; i < size; i++) {
		delete shape[i];
	}
}

int main()
{ 

	Shape* shape[SHAPE_NUM];
	int count = 0;
	shapeInit(shape, SHAPE_NUM);
	Shape** shapeArea50 = selectArea50(shape, SHAPE_NUM, count);

	for (int i = 0; i < count; i++) {
		cout <<"size:"<<shapeArea50[i]->getArea() << endl;
	}
	shapeDel(shape, count);
	if (shapeArea50)
		delete[] shapeArea50;
	return 0;
}