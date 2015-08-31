#include "StdAfx.h"
#include "Rectangle.h"
 
Rectangle::Rectangle(int width, int height, int x, int y):width(width),height(height),leftUp(new Point(x,y))
{
 
}
 Rectangle::Rectangle(const Rectangle& other)
{
	this->Height(other.Height());
	this->Width(other.Width());
	this->LeftUp(new Point(other.LeftUp()->X(),other.LeftUp()->Y()));
}
 inline Rectangle& Rectangle::operator=(const Rectangle& other)
{
	this->Height(other.Height());
	this->Width(other.Width());
	//delete 
	delete this->leftUp;
	this->LeftUp(new Point(other.LeftUp()->X(),other.LeftUp()->Y()));

	return *this;
}

Rectangle::~Rectangle(void)
{	
	delete leftUp;
}
