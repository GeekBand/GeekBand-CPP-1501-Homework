#ifndef __RECTANGLE__
#define __RECTANGLE__

#include "Point.h"
#include "Shape.h"

class Rectangle :public Shape
{
public:
	Rectangle(int width = 0, int height = 0, int x = 0, int y = 0) :width(width), height(height), leftUp(Point(x, y)) {}
	int getArea() override { return width * height; }

private:
	int width;
	int height;
	Point leftUp;
};

#endif
