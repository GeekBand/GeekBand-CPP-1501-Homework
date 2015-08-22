#include <stdio.h>
#include "rectangle.h"

Rectangle::Rectangle(int width, int height, int x, int y) :
width(width), height(height)
{
	if (leftUp == nullptr)
		leftUp = new Point;

	leftUp->x = x;
	leftUp->y = y;
}

Rectangle::Rectangle(const Rectangle& other)
{
	Rectangle(other.width, other.height, other.leftUp->x, other.leftUp->y);
}

Rectangle& Rectangle::operator =(const Rectangle& other)
{
	if (this == &other)
		return *this;

	width = other.width;
	height = other.height;
	leftUp->x = other.leftUp->x;
	leftUp->y = other.leftUp->y;
	return *this;
}

Rectangle::~Rectangle()
{
	if (leftUp != nullptr)
	{
		delete leftUp;
		leftUp = nullptr;
	}
}

void Rectangle::PrintDetail() const
{
	printf("StartPoint: x = %d, y = %d\nWidth = %d\nHeight = %d\n",
		leftUp->x, leftUp->y, width, height);
}

