#pragma once

#ifndef __SHAPE_H__
#define __SHAPE_H__

class Shape
{
	int no;
public:
	Shape() {};
	Shape(int no_in): no(no_in) {};
	virtual ~Shape() {};

	int getNo() { return no; };
	virtual int getArea() = 0;
	virtual void outputInfo() = 0;
};

class Point
{
	int x;
	int y;
public:
	Point(int x_in, int y_in) : x(x_in), y(y_in) {};
	Point(Point& point_in) : x(point_in.x), y(point_in.y) {};

	int getx() { return x; };
	int gety() { return y; };
};

class Rectangle : public Shape
{
	int width;
	int height;

	Point leftUp;

public:
	Rectangle(int w_in, int h_in, int x_in, int y_in, int no) : width(w_in), height(h_in), leftUp(x_in, y_in), Shape(no) {};
	virtual Rectangle& operator=(const Rectangle& other);

	int getWidth() { return width; };
	int getHeight() { return height; };
	virtual int getArea();
	virtual void outputInfo();
};

class Circle :public Shape
{
	Point	center;
	int		radius;

public:
	Circle(int x_in, int y_in, int r_in, int no) : center(x_in, y_in), radius(r_in), Shape(no) {};
	virtual Circle& operator=(const Circle& other);

	int getRadius() { return radius; };
	virtual int getArea();
	virtual void outputInfo();
};

#endif
