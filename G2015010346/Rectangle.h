#pragma once

#include "Sharp.h"

class Point;

class Rectangle : public Sharp
{
public:
	Rectangle(int n, int w, int h, Point* p);
	Rectangle(int n);

	Rectangle(const Rectangle& orig);
	Rectangle& operator=(const Rectangle& rhs);

	~Rectangle();

private:
	int width;
	int height;
	Point *leftUp;
};

