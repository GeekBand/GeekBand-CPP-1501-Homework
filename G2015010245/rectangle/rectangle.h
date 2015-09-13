#ifndef __RECTANGLE__
#define __RECTANGLE__

#include <iostream>
#include <cstring>
using namespace std;

class Shape
{
	int no;
};

class Point
{
public:   
	int x;
	int y;

	Point(int x1, int y1): x(x1), y(y1)
	{
	}
};

class Rectangle: public Shape
{
	int width;
	int height;

	Point *leftUp;

public:
	Rectangle(int width1 = 0, int height1 = 0, int x1 = 0, int y1 = 0);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();
};

inline Rectangle::Rectangle(int width1, int height1, int x1, int y1)
: width(width1), height(height1)
{
	leftUp = new Point(x1, y1);
	
	cout << "Rectangle(int width1, int height1, int x1, int y1)" << endl;
	cout << "(" << width << ", " << height << ", " << leftUp->x << ", " << leftUp->y << ")" << endl;
}

inline Rectangle::Rectangle(const Rectangle& other)
: width(other.width), height(other.height)
{
	leftUp = new Point(other.leftUp->x, other.leftUp->y);
	
	cout << "Rectangle(const Rectangle& other)" << endl;
	cout << "(" << width << ", " << height << ", " << leftUp->x << ", " << leftUp->y << ")" << endl;
}

inline Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this == &other)
	{
		return *this;
	}

	width = other.width;
	height = other.height;
	memcpy(leftUp, other.leftUp, sizeof(Point));

	cout << "Rectangle& operator=(const Rectangle& other)" << endl;
	cout << "(" << width << ", " << height << ", " << leftUp->x << ", " << leftUp->y << ")" << endl;

	return *this;
}

inline Rectangle::~Rectangle()
{
	cout << "~Rectangle()" << endl;
	cout << "(" << width << ", " << height << ", " << leftUp->x << ", " << leftUp->y << ")" << endl;

	delete leftUp;
}

#endif
