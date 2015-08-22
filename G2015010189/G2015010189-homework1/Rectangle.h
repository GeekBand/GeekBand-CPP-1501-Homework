#pragma once
#include "stdafx.h"
class Shape
{
private:
	int no;
public:
	Shape(int no):no(no){}
	virtual ~Shape(){}
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
		x=p.x;
		y=p.y;
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
	Rectangle(int width=0, int height=0, int x=0, int y=0, int no=0)
		: width(width), height(height),leftUp(new Point(x, y)),Shape(no)
	{}
	Rectangle(const Rectangle& other);
	Rectangle& operator = (const Rectangle& other);
	~Rectangle()
	{
		delete leftUp;
		leftUp=nullptr;
	}

	int get_width() const{ return width; }
	int get_height() const{ return height; }
	Point& get_leftUp() const { return *leftUp; }
};

inline
Rectangle::Rectangle(const Rectangle& other)
 : Shape(other), width(other.width), height(other.height)
{
	if(other.leftUp==nullptr)
		leftUp = nullptr;
	else
	{
		leftUp=new Point(*other.leftUp);
	}
}

inline
Rectangle& Rectangle::operator = (const Rectangle& other)
{
	if(this != &other)
	{
		this->Shape::operator=(other); 
		width = other.width;
		height = other.height;
		if(this->leftUp != other.leftUp)
		{
		//else
			if(leftUp != nullptr && other.leftUp != nullptr)
			{
				*leftUp = *other.leftUp;
			}
			if(leftUp == nullptr)
			{
				leftUp = new Point(*other.leftUp);
			}
			if(other.leftUp == nullptr)
			{
				delete leftUp;
				leftUp = nullptr;
			}
		}
	}
	return *this;
};

#include <iostream>
using namespace std;
ostream& operator<<(ostream& os, const Rectangle& Rec)
{
	Point* newp=new Point(Rec.get_leftUp());
	os << "width : " << Rec.get_width() << endl 
		<< "height : " << Rec.get_height() << endl
		<<"leftUp Point: (" << newp->get_x() << " , " << newp->get_y()
		 << ")" << endl;
   return os;
}