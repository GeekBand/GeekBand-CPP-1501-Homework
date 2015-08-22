#include "Rectangle.h"
#include "Point.h"


Rectangle::Rectangle(int no, int w, int h, Point* p) 
	: Sharp(no), width(w), height(h), leftUp(p)
{
}
Rectangle::Rectangle(int no)
	: Rectangle(no, 0, 0, new Point(0, 0))
{
}

Rectangle::Rectangle(const Rectangle& orig) : Sharp(orig.getNo())
{
	width = orig.width;
	height = orig.height;

	leftUp = new Point(*(orig.leftUp));
}

Rectangle& 
Rectangle::operator=(const Rectangle& rhs)
{
	width = rhs.width;
	height = rhs.height;

	Point* pOld = rhs.leftUp;
	leftUp = new Point(*(rhs.leftUp));
	delete pOld;

	return *this;
}

Rectangle::~Rectangle()
{
	delete leftUp;
}
