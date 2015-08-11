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
	Point(int _x, int _y): x(_x), y(_y){}
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

Rectangle::Rectangle(const Rectangle& other): width(other.width), height(other.height), leftUp(new Point(*other.leftUp)){ }

Rectangle& Rectangle::operator=(const Rectangle& other){
	if(this == &other){
		return *this;
	}
	delete leftUp;
	width = other.width;
	height = other.height;
	leftUp = new Point(*other.leftUp);
	return *this;
}

Rectangle::~Rectangle(){
	delete leftUp;
	leftUp = NULL;
}

#endif