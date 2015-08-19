#pragma once
#include "Shape.h"

class Rectangle : public Shape {
	int width, height;
	Point leftUp;

	static Rectangle rectangle;
public:
	Rectangle() {
		Shape::add_property(this);
	}
	Rectangle(int w, int h, const Point & lU) :
		width(w), height(h), leftUp(lU) {}

public:
	int getArea() {
		return width*height;
	}
	int getType() {
		return 0;
	}
	Shape* clone(Shape *src = nullptr) {
		if (src != nullptr) {
			Rectangle *rect = (Rectangle *)src;
			return new Rectangle(*rect);
		}
		else {
			return new Rectangle;
		}
	}
};
Rectangle Rectangle::rectangle;