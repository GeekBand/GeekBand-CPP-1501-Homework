#include "rectangle.h"
#include <iostream>

using namespace std;

inline
Rectangle::Rectangle(int width, int height, int x, int y): \
		Shape(0), width(width), height(height)
{
	leftUp = new Point(x, y);
}

inline
Rectangle::Rectangle(const Rectangle& rectangle)
{
	this->width = rectangle.get_width();
	this->height = rectangle.get_height();
	this->leftUp = new Point(rectangle.get_leftup_x(), rectangle.get_leftup_y());
}

inline
Rectangle& Rectangle::operator=(const Rectangle& rectangle)
{
	if(this == &rectangle){
		return *this;
	}
	this->width = rectangle.get_width();
	this->height = rectangle.get_height();
	delete this->leftUp;
	this->leftUp = new Point(rectangle.get_leftup_x(), rectangle.get_leftup_y());
	return *this;
}

inline
Rectangle::~Rectangle()
{
	delete this->leftUp;
}

inline
ostream& operator<<(ostream& os, const Rectangle& rectangle)
{
	os<<"rectangle: width("<<rectangle.get_width()<<"), height("<<rectangle.get_height()<<")"<<endl;
	os<<"leftup position: ("<<rectangle.get_leftup_x()<<", "<<rectangle.get_leftup_y()<<")"<<endl;
	return os; 
}

