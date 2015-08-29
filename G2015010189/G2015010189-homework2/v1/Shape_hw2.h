#pragma once
const double pi = 3.1415926;
class Shape
{
private:
	int no;
public:
	Shape(int no): no(no){}
	virtual const int getArea()=0;
	virtual ~Shape(){}
};

class Point
{
private:
	int x;
	int y;
public:
	Point(int x=0,int y=0):x(x), y(y){}
	Point& operator = (const Point& p)
	{
		x=p.x;
		y=p.y;
		return *this;
	}
};

class Rectangle: public Shape
{
private:
	int width;
	int height;
	Point leftUp;
public:
	Rectangle(int no, int width, int height, Point& point):Shape(no), width(width), height(height), leftUp(point)
	{}
	virtual const int getArea()
	{
		return width*height;
	}
};

class Circle: public Shape
{
private:
	Point center;
	int radius;
public:
	Circle(int no, int r, Point& p):Shape(no), radius(r), center(p){}
	virtual const int getArea()
	{
		return pi * radius * radius;
	}
};