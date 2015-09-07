#pragma once
class Point
{
public:
	Point(int _x, int _y);

	Point(const Point& orig);
	Point& operator=(const Point& rhs);

	~Point();
private:
	int x;
	int y;
};

