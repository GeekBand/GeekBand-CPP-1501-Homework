#ifndef _shape
#define _shape

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
class Shape
{
	int no;
	public:
	virtual int getArea()=0;
	virtual void printTest()=0;
};
class Point
{
	int x;
	int y;
public:
	void setPoint(int inputX,int inputY){x=inputX;y=inputY;}
	void printTest(){cout<<" x="<< x << " y=" << y <<'\n';}
};
class Rectangle: public Shape
{
	int width;
	int height;
	Point leftUp;
public:
	int getArea();
	Rectangle(int x =1,int y =1,int w = 1,int h = 1)
	{
		leftUp.setPoint(x,y);
		width = w;
		height = h;
	}
	void printTest()
	{
		cout<<"Rectangle\n";
		leftUp.printTest();
		cout<<" width= "<< width << " height= "<< height<<'\n';
	}
};
class Circle: public Shape
{
	Point center;
	int radius;
public:
	int getArea();
	Circle(int x = 1,int y = 1,int r = 1)
	{
		center.setPoint(x,y);
		radius = r;
	}
	void printTest()
	{
		cout<<"Circle\n";
		center.printTest();
		cout<<" radius= "<< radius << "\n";
	}
};

int Rectangle::getArea()
{
	int area = width * height / 2;
	return area;
}

int Circle::getArea()
{
	int area = radius*radius * M_PI;
	return area;
}

#endif