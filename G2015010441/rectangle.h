#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include <iostream>
using namespace std;

class Shape
{
public:
	Shape(int _no = 0)
		: no(_no) { }
    virtual ~Shape() { }
private:
	int no;
};

class Point
{
public:
	Point(int _x = 0, int _y = 0)
		: x(_x), y(_y) {}
    ~Point() { }
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}

private:
	int x;
	int y;
};


class Rectangle : public Shape
{
public:
	Rectangle(int _width = 0, int _height = 0, int _x = 0, int _y = 0);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();

	int getWidgth() const {
        return width;
	}

	int getHeight() const {
        return height;
	}

	Point* getLeftUpPoint() const {
        return leftUp;
	}

private:
	int width;
	int height;
	Point* leftUp;
};

#endif
