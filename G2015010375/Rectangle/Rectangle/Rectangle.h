#ifndef __RECTANGLE__
#define __RECTANGLE__

#include "Shape.h"
#include "Point.h"

class Rectangle :public Shape
{
public:
	Rectangle(int width, int height, int x, int y) :width(width), height(height), leftUp(new Point(x, y))
	{
	}

	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();

private:
	int width, height;
	Point* leftUp;
};

#endif
inline
Rectangle::Rectangle(const Rectangle& other) :Shape(other), width(other.width), height(other.height)
{
	if (other.leftUp == nullptr)
	{
		leftUp = nullptr;
	}
	else
	{
		leftUp = new Point(*other.leftUp);
	}
}

inline Rectangle&
Rectangle::operator=(const Rectangle& other)
{
	if (this == &other)
		return *this;

	this->Shape::operator=(other);

	if (other.leftUp != nullptr && leftUp != nullptr)
	{
		*leftUp = *other.leftUp;
	}
	else if (other.leftUp == nullptr)
	{
		delete leftUp;
	}
	else
	{
		leftUp = new Point(*other.leftUp);
	}

	return *this;
}

inline
Rectangle::~Rectangle() {
	delete this->leftUp;
}

