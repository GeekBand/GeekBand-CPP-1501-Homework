#include "Polygon.h"
#include <iostream>


Polygon::Polygon(const Polygon & other)
{
	points = new Point[other.count];
	if (points == NULL)
		return;

	for (int i = 0; i < other.count; ++i)
	{
		points[i] = other.points[i];
	}

	return;
}

Polygon::Polygon(const Point * p, int input_count, int input_no)
			: count(input_count), Shape(input_no)
{
	if ((p == NULL) || (input_count <= 0))
	{
		points = NULL;
		count = 0;
		return;
	}
	
	points = new Point[input_count];
	if (points == NULL)
		return;

	for (int i = 0; i < input_count; ++i)
	{
		points[i] = p[i];
	}
}

Polygon::~Polygon()
{
	if (points != NULL)
	{
		delete[] points;
	}
	count = 0;
}

Polygon & Polygon::operator=(const Polygon & other)
{
	if (this == &other)
	{
		return *this;
	}

	if (points != NULL)
	{
		delete[] points;
	}
	count = 0;

	points = new Point[other.count];
	if (points == NULL)
		return *this;

	for (int i = 0; i < other.count; ++i)
	{
		points[i] = other.points[i];
	}
	return *this;
}


int main()
{
	
	return 0;
}
