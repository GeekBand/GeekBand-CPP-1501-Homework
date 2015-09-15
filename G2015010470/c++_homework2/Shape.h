#pragma once
#ifndef _SHAPE_H
#define _SHAPE_H

#include <iostream>

class Shape
{
	int no;
public:
	Shape(int no) : no(no) {};
	virtual int getArea() const = 0;
	virtual std::ostream& print(std::ostream& out) const {
		return out << no;
	}
	virtual ~Shape() {}
};

class Point
{
	int x;
	int y;
public:
	Point() = default;
	Point(int x, int y):x(x), y(y) {};
	int getX() const { return x; };
	int getY() const { return y; };
};

class Rectangle: public Shape
{
	friend std::ostream& operator<<(std::ostream& os, const Shape& rect);
	Point position;
	int width;
	int height;
public:
	Rectangle(int no, int x, int y, int width, int height) : 
		Shape(no), position(x, y), width(width), height(height){}
	int getArea() const { return width * height; }

	std::ostream& print(std::ostream& out) const;
};

class Circle : public Shape
{
	friend std::ostream& operator<<(std::ostream& os, const Shape& circle);
	const double pi = 3.14;
	Point position;
	int radius;
public:
	Circle(int no, int x, int y, int radius) :
		Shape(no), position(x, y), radius(radius) {}
	int getArea() const { return pi*radius*radius; }
	std::ostream& print(std::ostream& out) const;
};

inline std::ostream &operator<<(std::ostream& os, const Shape& shape) {
	return shape.print(os);
}

inline 	std::ostream& Rectangle::print(std::ostream& out) const {
	Shape::print(out);
	out << " x:" << position.getX() << ", y:" << position.getY() <<
		", width" << width << ", height" << height << ", area:" << getArea();
	return out;
}

inline std::ostream& Circle::print(std::ostream& out) const {
	Shape::print(out);
	out << "x:" << position.getX() << ", y:" << position.getY() <<
		", radius:" << radius << ", area:" << getArea();
	return out;
}


#endif
