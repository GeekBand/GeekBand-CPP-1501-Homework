#ifndef _Rectangle_
#define _Rectangle_
#include "Point.h"
#include "Shape.h"
class Rectangle:public Shape{
private:
	int width;
	int height;
	Point leftUP; 
	
public:
	virtual int getArea()const override;

	Rectangle(int width, int height, int x, int y);		
};
Rectangle::Rectangle(int width, int height, int x, int y)
			:width(width), height(height), leftUP(Point(x,y)){}

int Rectangle::getArea()const{
	return width*height;
}


class Circle:public Shape
{
private:
	Point center;
	int radius;
	
public:
 	virtual int getArea()const override;
	Circle(int r,int x,int y):radius(r),center(Point(x,y)){};
 
};
int Circle::getArea()const{
	return radius*radius*3.14;
}


#endif
