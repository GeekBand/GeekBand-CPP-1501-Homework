#include "Rectangle.h"


Rectangle::Rectangle(int width, int height, int x, int y):width(width), height(height), leftUp(new Point)
{
	leftUp->x = x;
	leftUp->y = y;
}

Rectangle::Rectangle(const Rectangle & other)
{
}

Rectangle & Rectangle::operator=(const Rectangle & other)
{
	// TODO: �ڴ˴����� return ���
}

Rectangle::~Rectangle()
{
}
