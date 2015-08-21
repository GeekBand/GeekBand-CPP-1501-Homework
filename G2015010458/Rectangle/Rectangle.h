#pragma once
#include "Point.h"
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(int width = 0, int height = 0, int left = 0, int up = 0);
	Rectangle(const Rectangle& other);
	Rectangle& operator = (const Rectangle& other);

	virtual ~Rectangle();

private:

	int _width;
	int _height;
	Point* _pleftUp;

};
