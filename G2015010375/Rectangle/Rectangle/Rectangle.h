#ifndef __RECTANGLE__
#define __RECTANGLE__

#include "Shape.h"
#include "Point.h"

class Rectangle :public Shape
{
public:
	Rectangle(int width, int height, int x, int y) :width(width), height(height)
	{
		leftUp = new Point(x, y);
	}

	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();

	int getWidth() const { return width; }
	int getHeight() const { return height; }
	Point getPoint() const { return *leftUp; }
	void setPoint(const Point &p);

	static void copy(Rectangle* r1, const Rectangle& r2);

private:
	int width, height;
	Point* leftUp;
};

#endif

inline void
Rectangle::copy(Rectangle* r1, const Rectangle& r2)
{
	r1->width = r2.width;
	r1->height = r2.height;

	if (r1->leftUp == r2.leftUp)
		return;

	if (r2.leftUp == 0)
	{
		delete r1->leftUp;
		return;
	}

	if (r1->leftUp == 0)
	{
		r1->leftUp = new Point(*r2.leftUp);
	}
	else
	{
		*r1->leftUp = *r2.leftUp;
	}
}

inline
Rectangle::Rectangle(const Rectangle& other)
{
	Rectangle::copy(this, other);
}

inline Rectangle&
Rectangle::operator=(const Rectangle& other)
{
	if (this == &other)
		return *this;

	delete this->leftUp;
	this->leftUp = 0;
	Rectangle::copy(this, other);

	return *this;
}

inline
Rectangle::~Rectangle() {
	delete this->leftUp;
}

inline void
Rectangle::setPoint(const Point &p)
{
	if (this->leftUp == 0)
	{
		this->leftUp = new Point(p);
	}
	else
	{
		*this->leftUp = p;
	}
}


