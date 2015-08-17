#ifndef _CIRCLE_
#define _CIRCLE_
#define M_PI 3.1415926


#include "Shape.h"
#include "Point.h"

class Circle:public Shape{

private:
	Point center;
	int radius;

public:
	Circle(int radius_p, int x_p, int y_p) : radius(radius_p)
	{
		this->center = new Point(x_p, y_p);
	}

	Circle(int radius_p, const Point& p_p) : radius(radius_p)
	{
		this->center = new Point(p_p.width, p_p.height);
	}

	int getArea()
	{
		return M_PI * this->radius * this->radius;
	}

};

#endif
