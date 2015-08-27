#pragma once
class Point
{
public:
	Point(int x = 0, int y = 0) :_x(x), _y(y){}

	Point(const Point& other) :_x(other._x), _y(other._y) {}

private:
	int _x;
	int _y;
};

