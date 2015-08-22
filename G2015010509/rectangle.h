#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

class Shape
{
	int no;
};
class Point
{
	int x;
	int y;
public:
	Point(int x, int y) : x(x), y(y) {}
};
class Rectangle : public Shape
{
	int width;
	int height;
	Point * leftUp;
public:
	Rectangle(int width, int height, int x, int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();
};

inline Rectangle::Rectangle(int width, int height, int x, int y)
	: width(width), height(height) {
	leftUp = new Point(x, y);
}

inline Rectangle::Rectangle(const Rectangle& other)
	: width(other.width), height(other.height) {
	leftUp = new Point(*other.leftUp);
}

inline Rectangle& Rectangle::operator=(const Rectangle& other) {
	if (this == &other) return *this;

	width = other.width;
	height = other.height;

	*leftUp = *other.leftUp;

	return *this;
}

inline Rectangle::~Rectangle() {
	delete leftUp;
}

#endif // _RECTANGLE_H_

