#include "point.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"

using namespace Geekband;

#define OUT_PARAM
#define NUM 20
#define R10 (1 + rand() % 10)


void fill(OUT_PARAM Shape** shapes, int num)
{
	for (int i = 0; i < num; i++)
	{
		if(i < (num >> 1)) {
			shapes[i] = new Rectangle(R10, R10, R10, R10, i);
		} else {
			shapes[i] = new Circle(R10, R10, R10, i);
		}
	}
}

void filter(Shape** shapes, int num, OUT_PARAM Shape** result, int* len)
{
	if(len <= 0) {
		return;
	}
	
	for (int i = 0; i < num; i++)
	{
		if(shapes[i] != 0 && shapes[i]->getArea() >= 50) {
			result[(*len)++] = shapes[i];
		}
	}
}

void main(void)
{
	Shape* shapes[NUM];

	Shape* result[NUM];
	int len = 0;

	fill(shapes, NUM);

	filter(shapes, NUM, result, &len);

	delete[] shapes;
	delete[] result;

	getchar();
}