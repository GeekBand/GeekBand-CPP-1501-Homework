#include "Rectangle.h"


//******************************************************
void Shape::setNo(int no)
{
	this->no = no;
}

int Shape::getNo() const
{
	return this->no;
}
//******************************************************
Point::Point(int inputX,int inputY):x(inputX),y(inputY)
{	
}
int Point::getX() const
{
	return this->x;
}
int Point::getY() const
{
	return this->y;
}
void Point::setX(int x)
{
	this->x = x;
}
void Point::setY(int y)
{
	this->y = y;
}

//******************************************************
Rectangle::Rectangle(int width,int height,int x,int y):width(width),height(height)
{
	this->leftUp = new Point(x,y);

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

int Rectangle::getWidth() const
{
	return this->width;

}

int Rectangle::getHeight() const
{
	return this->height;

}

void Rectangle::setWidth(int width)
{
	this->width = width;

}

void Rectangle::setHeight(int height)
{
	this->height = height;

}	

Point* Rectangle::getLeftUp() const
{
	return this->leftUp;
}
