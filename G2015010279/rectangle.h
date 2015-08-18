#ifndef _RECTANGLE_
#define _RECTANGLE_

class Shape {
	int no;
};

class Point {
	int x;
	int y;
	
	public:
		Point(int _x, int _y) : x(_x), y(_y) {}
		Point(const Point& other) : x(other.x), y(other.y) {}
};


class Rectangle : public Shape {
	int width;
	int height;
	
	Point* leftUp;
	
	public:
		Rectangle(int width, int height, int x, int y);
		Rectangle(const Rectangle& other);
		Rectangle& operator=(const Rectangle& other);
		~Rectangle();
};

Rectangle::Rectangle(int width, int height, int x, int y) : width(width), height(height), leftUp(new Point(x, y)) {}

Rectangle::Rectangle(const Rectangle& other) : Shape(other), width(other.width), height(other.height) {
	if (other.leftUp != NULL) {
		this->leftUp = new Point(*other.leftUp);	
	}
	else {
		this->leftUp = NULL;
	}
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
	if (this == &other) {
		return *this;
	}
	
	this->Shape::operator=(other);
	this->width = other.width;
	this->height = other.height;
	
	if (other.leftUp != NULL) {
		if (this->leftUp == NULL) {
			this->leftUp = new Point(*other.leftUp);
		}
		else {
			*this->leftUp = *other.leftUp;
		}
	}
	else {
		if (this->leftUp != NULL) {
			delete this->leftUp;
			this->leftUp = NULL;
		}
	}	
	
	return *this;
}

Rectangle::~Rectangle() {
	delete leftUp;
	leftUp = NULL;
}

#endif
