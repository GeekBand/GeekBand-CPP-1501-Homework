#ifndef _RECTANGLE_
#define _RECTANGLE_

class Shape{
	int no;
public:
	virtual ~Shape(){}
};

class Point{
	int x;
	int y;
public:
	Point(int x, int y): x(x), y(y){}
};

class Rectangle: public Shape{
	int width;
	int height;
	Point *leftUp;

public:
	Rectangle(int width, int height, int x, int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	virtual ~Rectangle();
};

Rectangle::Rectangle(int width, int height, int x, int y): width(width), height(height), leftUp(new Point(x, y)){ }

Rectangle::Rectangle(const Rectangle& other): Shape(other), width(other.width), height(other.height), leftUp(new Point(*other.leftUp)){ }

Rectangle& Rectangle::operator=(const Rectangle& other){
	if(this == &other){
		return *this;
	}
	Shape::operator=(other);
	delete leftUp;
	leftUp = NULL;
	width = other.width;
	height = other.height;
	if(other.leftUp != NULL) {
		leftUp = new Point(*other.leftUp);
	}
	return *this;
}

Rectangle::~Rectangle(){
	delete leftUp;
	leftUp = NULL;
}

#endif
