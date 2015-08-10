#include "Rectangle.h"


Rectangle::Rectangle(int width,int height):width(width),height(height)
{
	this->leftUp = new Point();

}


Rectangle::Rectangle(const Rectangle &other):Shape(other),width(other.width),height(other.height)
{
	if(other.leftUp != 0)
	{ //my compiler does not support C++11
		this->leftUp = new Point(*other.leftUp);
	}
	else
	{
		this->leftUp = 0;
	}
	

}


Rectangle& Rectangle::operator=(const Rectangle &other)
{
	if(this == &other)
		return *this;

	//this->no = other.no;
	Shape::operator=(other);

	this->width = other.width;
	this->height = other.height;
	if (other.leftUp != this->leftUp)
	{
		
		if(other.leftUp != 0)
		{
			if (this->leftUp != 0)
			{
				*this->leftUp = *other.leftUp;
			}
			else
			{
				this->leftUp = new Point(*other.leftUp);				
			}

		}
		else
		{
			delete this->leftUp;
			this->leftUp = 0;
		}
	}
	return *this;
}


Rectangle::~Rectangle()
{
	delete this->leftUp ;
	this->leftUp = 0;
}
