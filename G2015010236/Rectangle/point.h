#ifndef POINT_H
#define POINT_H

class Point;

class Point
{
public:
	Point(int x = 0, int y = 0) : x_(x), y_(y) {}
	Point(const Point& other_point);
	Point& operator = (const Point& other_point);
	~Point() {}
	int x() const { return x_; }
	int y() const { return y_; }
	void set_x(int x) { x_ = x; }
	void set_y(int y) { y_ = y; }

private:
	int x_;
	int y_;
};

inline 
	Point::Point(const Point& other_point)
{
	x_ = other_point.x_;
	y_ = other_point.y_; 
}

inline Point&
	Point::operator= (const Point& other_point)
{
	x_ = other_point.x_; 
	y_ = other_point.y_; 
	return *this;
}

#include <iostream>

inline std::ostream&
	operator<< (std::ostream& os, const Point& point)
{
	os << "( " << point.x() << " , " << point.y() << " )";
	return os;
}
#endif