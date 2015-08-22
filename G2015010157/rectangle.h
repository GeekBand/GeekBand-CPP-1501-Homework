#ifndef __HEAD_H__
#define __HEAD_H__

class Shape
{
	int no;
public:
	virtual ~Shape(){}
};
class Point
{
	int x;
	int y;
public:
	Point(int x, int y) :x(x), y(y)
	{}
	Point() :x(0), y(0)
	{}
};
class Rectangle : public Shape
{
	int width;
	int height;
	Point * leftUp;
public:
	Rectangle(int width, int height, int x, int y) :width(width), height(height), leftUp(new Point(x, y))
	{
	}
	Rectangle(const Rectangle& other) :width(other.width), height(other.height), leftUp(new Point(*other.leftUp))
	{
	}
	Rectangle& operator=(const Rectangle& other)
	{
		if (this == &other)
			return *this;
		else
		{
			width = other.width;
			height = other.height;
			delete leftUp;
			leftUp = new Point(*other.leftUp);
		}

	}
	virtual ~Rectangle()
	{
		delete leftUp;
	}
};

#endif
