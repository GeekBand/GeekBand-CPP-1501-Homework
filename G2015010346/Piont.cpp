#include "Point.h"


Point::Point(const int _x = 0, const int _y = 0) : x(_x), y(_y)
{
}

Point::Point(const Point& orig) : x(orig.x), y(orig.y)
{
}

Point&
Point::operator=(const Point& rhs)
{
	x = rhs.x;
	y = rhs.y;

	return *this;
}

Point::~Point()
{
}
