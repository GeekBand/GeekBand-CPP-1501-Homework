#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "Point.h"	  
#include "Shape.h"  

#define PI 3.1415926

class Circle:public Shape
{
public:
	Circle(int r = 0, int x = 0, int y = 0):
		radius(r), center(Point(x, y))
	{}
	~Circle() = default;
	double getArea() const override
	{
		return PI * radius * radius;
	};


private:
	Point center;
	int radius;
};

#endif // _CIRCLE_H_
