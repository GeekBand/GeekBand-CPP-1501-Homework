#pragma once
#include "stdafx.h"
class Shape
{
private:
	int no;
};

class Point
{
private:
	int x;
	int y;
public:
	Point(int x=0, int y=0):x(x),y(y){}
	Point& operator = (const Point& p)
	{
		x = p.x;
		y = p.y;
		return *this;
	}
	int get_x() const { return x; }
	int get_y() const { return y; }
}; 

class Rectangle:public Shape
{
private:
	int width;
	int height;
	Point* leftUp;
public:
	inline Rectangle(int width=0, int height=0, int x=0, int y=0)
		: width(width), height(height)
	{
		leftUp = new Point(x, y);
	}
	Rectangle(const Rectangle& other);
	Rectangle& operator = (const Rectangle& other);
	inline ~Rectangle()
	{
		delete leftUp;
	}

	int get_width() const{ return width; }
	int get_height() const{ return height; }
	Point* get_leftUp() const { return leftUp; }
};

inline
Rectangle::Rectangle(const Rectangle& other)
{
	width = other.width;
	height = other.height;
	leftUp = other.leftUp;
}

inline
Rectangle& Rectangle::operator = (const Rectangle& other)
{
	if(this == &other)
		return *this;
	width = other.width;
	height = other.height;
	delete leftUp;
	leftUp = other.leftUp;
	return *this;
};

#include <iostream>
using namespace std;
ostream& operator<<(ostream& os, const Rectangle& Rec)
{
	Point* newp=Rec.get_leftUp();
	os << "width : " << Rec.get_width() << endl 
		<< "height : " << Rec.get_height() << endl
		<<"leftUp Point: (" << newp->get_x() << " , " << newp->get_y()
		 << ")" << endl;
   return os;
}