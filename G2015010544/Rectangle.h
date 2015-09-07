#ifndef __RECTANGLE__
#define __RECTANGLE__

#include "Shape.h"
#include "Point.h"

class Rectangle:public Shape
{

private:
	int width;
	int height:

	Point *leftUp;

public:
	Rectangle(int p_width, int p_height, int x, int y):width(p_width), height(p_height);
	{
		this->leftUp = new Point(x, y);
	}

	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();

	int getArea()
	{
		return this->width * this->height;
	}

};

inline Rectangle::Rectangle(const Rectangle& other) 
{
	this->width = other.width;
	this->height = other.height;

	this->leftUp = new Point(other->leftUp->getPointX(), other->leftUp->getPointY());
}

inline Rectangle& operator=(const Rectangle& other)
{
	if (this == &other)
	return *this;

	delete this->leftUp;
	this->width = other.width;
	this->height = other.height;
	this->leftUp = new Point(other->leftUp->getPointX(), other->leftUp->getPointY());
	return *this;
}

inline Rectangle::~Rectangle()
{
	delete this->leftUp;
}

#endif