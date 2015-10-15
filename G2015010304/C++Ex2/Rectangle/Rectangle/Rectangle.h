#pragma once
#define PI 3.14159
class Shape
{
	int no;
public:
	virtual int getArea() = 0;
	virtual ~Shape(){}
	void setNo(int _no) { no = _no; }
};
class Point
{
	int x;
	int y;
public:
	Point(int x, int y);
};
class Rectangle : public Shape
{
	int width;
	int height;
	Point leftUp;
public:
	Rectangle(int width, int height, int x, int y);
	Rectangle(int width, int height, Point leftUp);
	~Rectangle();
public:
	int getArea() { return width * height; }
};
class Circle : public Shape
{
	Point center;
	int radius;
public:
	Circle(int x, int y, int radius);
	~Circle();
public:
	int getArea() { return radius * radius * PI; }
};