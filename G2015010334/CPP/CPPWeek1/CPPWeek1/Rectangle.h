#pragma once

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <memory>
using namespace std;

class Shape
{
	int no;

public:
	Shape(int param = 0) { no = param; };
	int getno() const { return no; };
};

class Point
{
	int x;
	int y;

public:
	Point(int xparam, int yparam) { x = xparam; y = yparam; };
	int getX() const { return x; };
	int getY() const { return y; };
};

class Rectangle :public Shape
{
	int width;
	int height;

	unique_ptr<Point> leftUp;

public:
	Rectangle(int widthparam, int heightparam, int x, int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();

	int getW() const { return width; };
	int getH() const { return height; };
	Point * getPoint() { return leftUp.get(); };
};

#endif //__RECTANGLE_H__
