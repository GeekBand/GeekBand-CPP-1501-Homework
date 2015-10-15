#include <iostream>
#include <math.h>
#include "Shape.h"

using namespace std;

const double pi = acos(-1.0);

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this == &other)
	{
		return *this;
	}

	Shape::operator=(other);

	width = other.width;
	height = other.height;
	leftUp = other.leftUp;
}

int Rectangle::getArea()
{
	return width * height;
}

void Rectangle::outputInfo()
{
	cout << "\tRectangle width=" << width << " Height=" << height << " leftUp x=" << leftUp.getx() << " y=" << leftUp.gety() ;
}

Circle& Circle::operator=(const Circle& other)
{
	if (this == &other)
	{
		return *this;
	}

	Shape::operator=(other);

	center = other.center;
	radius = other.radius;
}

int Circle::getArea()
{
	return (int)( pi * radius * radius);
}

void Circle::outputInfo()
{
	cout << "\tCircle radius=" << radius << " Center x=" << center.getx() << " y=" << center.gety();
}

