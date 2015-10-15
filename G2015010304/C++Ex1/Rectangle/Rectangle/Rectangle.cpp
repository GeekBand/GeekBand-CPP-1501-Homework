#include "Rectangle.h"


Rectangle::Rectangle(int width, int height, int x, int y) : width(width), height(height), leftUp(new Point(x, y))
{
}

Rectangle::Rectangle(const Rectangle & other) : width(other.width), height(other.height), leftUp(new Point(*other.leftUp))
{
}

Rectangle & Rectangle::operator=(const Rectangle & other)
{
	// TODO: 在此处插入 return 语句
	if (&other != this) {
		delete leftUp;
		leftUp = new Point(*other.leftUp);
		width = other.width;
		height = other.height;
	}
	return *this;
}

Rectangle::~Rectangle()
{
	if (leftUp) {
		delete leftUp;
	}
}