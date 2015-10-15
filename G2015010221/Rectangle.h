#ifndef __Rectangle__
#define __Rectangle__

#include <iostream>

using std::cout;
using std::endl;

class Shape
{
	int no;

public:
	int get_no() { return no; }
};

class Point
{
	int x;
	int y;

public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	int get_x() { return x; }
	int get_y() { return y; }


};

class Rectangle :public Shape
{
	int width;
	int height;

	Point* leftUp;

public:
	Rectangle(int width, int height, int x, int y);

	Rectangle(const Rectangle& other);

	Rectangle& operator=(const Rectangle& other);

	~Rectangle();


	void display()
	{
		cout << "width:" << width << " height:" << height
			<< " x:" << leftUp->get_x() << " y:" << leftUp->get_y() << endl;
	}
};

inline
Rectangle::Rectangle(int width, int height, int x, int y)
{
	this->width = width ? width : 0;
	this->height = height ? height : 0;

	this->leftUp = new Point(x, y);
}


inline
Rectangle::Rectangle(const Rectangle& other)
: Shape(other), width(other.width), height(other.height)
{
	if (other.leftUp != nullptr)
	{
		this->leftUp = new Point(*other.leftUp);
	}
	else
	{
		this->leftUp = nullptr;
	}
}

inline
Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this == &other)
	{
		return *this;
	}

	Shape::operator = (other);

	this->width = other.width;
	this->height = other.height;

	delete leftUp;
	if (other.leftUp != nullptr)
	{
		this->leftUp = new Point(*other.leftUp);
	}
	else
	{
		this->leftUp = nullptr;
	}


	return *this;
}

inline
Rectangle::~Rectangle()
{
	delete[] leftUp;
	leftUp = nullptr;
}

#endif


