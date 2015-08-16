#include "rectangle.h"


Rectangle::Rectangle(int _width, int _height, int _x, int _y)
	: Shape(), width(_width), height(_height), leftUp(new Point(_x, _y))
{

}

Rectangle::Rectangle(const Rectangle& other)
	: Shape(), width(other.width), height(other.height)
{
	if(other.leftUp != NULL)
	{
		leftUp = new Point(other.leftUp->getX(), other.leftUp->getY());
	}
	else
		leftUp = NULL;
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if(this == &other)
		return *this;

	width = other.width;
	height = other.height;

	if(this->leftUp != other.leftUp)
	{
		if(other.leftUp != NULL)
		{
			if(leftUp != NULL)
				delete leftUp;

			leftUp = new Point(other.leftUp->getX(), other.leftUp->getY());
		}
		else
		{
			delete leftUp;
			leftUp = NULL;
		}
	}

    return *this;
}

Rectangle::~Rectangle()
{
	if(leftUp != NULL)
		delete leftUp;
}
