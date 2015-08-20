#ifndef __RECTANGLE__
#define __RECTANGLE__
#include "Point.h"
#include "Shape.h"

class Rectangle:public Shape{
private:
	int width;
	int height;

	Point* leftUp;

public:
	Rectangle(int width, int height, int x, int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();
};
inline Rectangle::Rectangle(int width, int height, int x, int y) : Shape(), width(width), height(height), leftUp(new Point(x, y)){

}
inline Rectangle::Rectangle(const Rectangle& other) : Shape(other), width(other.width), height(other.height){
	if (other.leftUp != nullptr){
		leftUp = new Point(*other.leftUp);
	}
	else{
		leftUp = nullptr;
	}
}
inline Rectangle& Rectangle::operator=(const Rectangle& other){
	if (this == &other){
		return *this;
	}
	else{
		Shape::operator=(other);
		width = other.width;
		height = other.height;
		if (leftUp != nullptr && other.leftUp != nullptr){
			*leftUp = *other.leftUp;
		}
		else if (other.leftUp == nullptr && leftUp != nullptr){
			delete leftUp;
			leftUp = nullptr;
		}
		else if (other.leftUp == nullptr && leftUp == nullptr){

		}
		else{
			leftUp = new Point(*other.leftUp);
		}
		return *this;
	}
}
inline Rectangle::~Rectangle(){
	delete leftUp;
	leftUp = nullptr;
}

#endif