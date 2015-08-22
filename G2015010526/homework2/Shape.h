#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
public:
	Shape(int num = 0) : no(num) {}
	virtual ~Shape() {}
	virtual int getArea()=0;
private:
	int no;
};


class Point 
{
public:
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
private:
	int x;
	int y; 
};


class Rectangle : public Shape
{
public:
	Rectangle() {}
	Rectangle(int n, int w, int h, const Point& p) : Shape(n), width(w), height(h), leftUp(p) {}

	int getArea() {
		return width*height;
	}

	// 用于测试内存是否正常释放
	~Rectangle() {
		std::cout << "Rectangle 析构" << std::endl;
	}

private:
	int width;
	int height;
	Point leftUp; 
};


class Circle : public Shape
{
public:
	Circle() {}
	Circle(int n, int r, const Point& p) : Shape(n), radius(r), center(p) {}

	int getArea() {
		return static_cast<int>(3.14*radius*radius);
	}
	
	~Circle() {
		std::cout << "Circle 析构" << std::endl;
	}

private:
	Point center; 
	int radius;
};


#endif