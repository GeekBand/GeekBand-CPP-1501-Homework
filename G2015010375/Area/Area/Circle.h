#ifndef __CIRCLE__
#define __CIRCLE__

#include "Point.h"
#include "Shape.h"

#define PI 3.14

class Circle :public Shape
{
public:
	Circle(int r = 0, int x = 0, int y = 0) :radius(r), center(Point(x, y)) {}
	int getArea() { return PI * radius * radius; }

private:
	Point center;
	int radius;
};

#endif