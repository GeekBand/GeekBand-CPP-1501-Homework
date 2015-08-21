#include <memory>
#include "Rectangle.h"

Rectangle::Rectangle(int widthparam, int heightparam, int x, int y)
{
	width = widthparam;
	height = heightparam;
	leftUp = make_unique<Point>(x, y);
}

Rectangle::~Rectangle()
{
	leftUp.reset();
}

Rectangle::Rectangle(const Rectangle& other)
	: Shape(other.getno())
{
	width = other.width;
	height = other.height;
	leftUp = make_unique<Point>(other.leftUp->getX(), other.leftUp->getY());
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this == &other)
	{
		return *this;
	}

	width = other.width;
	height = other.height;
	leftUp.reset(new Point(other.leftUp->getX(), other.leftUp->getY()));
	return *this;
}

