#include "stdafx.h"
#include "Rectangle.h"


inline Rectangle::Rectangle(int width, int height, int left, int up)
	:Shape(0), _width(width), _height(height), _pleftUp(new Point(left, up))
{
	if (width < 0) _width = 0;
	if (height < 0) _height = 0;
}

inline Rectangle::Rectangle(const Rectangle& other)
	: Shape(0), _width(other._width), _height(other._height), _pleftUp(new Point(*other._pleftUp))
{
	
}

inline Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this == &other)
		return *this;

	delete _pleftUp;

	this->_width = other._width;
	this->_height = other._height;
	this->_pleftUp = new Point(*other._pleftUp);

	return *this;
}

inline Rectangle::~Rectangle()
{
	delete _pleftUp;
	_pleftUp = nullptr;
}

