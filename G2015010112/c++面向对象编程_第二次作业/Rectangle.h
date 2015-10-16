#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Point.h"  
#include "Shape.h"  

class Rectangle: public Shape
{
public:
	Rectangle(int w = 0, int h = 0, int x = 0, int y = 0):
		width(w), height(h), leftUp(Point(x, y))
	{}
	~Rectangle() = default;
	double getArea() const override
	{
		return width * height;
	};

private:
	int width;
	int height;

	Point leftUp;
};

#endif // _RECTANGLE_H_
