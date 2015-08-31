#pragma once
#include "Shape.h"

class Circle : public Shape {
	int radius;
	Point center;

	static Circle circle;
public:
	Circle() {
		Shape::add_property(this);
	}
	Circle(int ra, const Point& cen) :radius(ra), center(cen) {}
public:
	int getArea() {
		return static_cast<int>(radius*radius*M_PI);
	}
	int getType() {
		return 1;
	}
	Shape* clone(Shape *src = nullptr) {
		if (src != nullptr) {
			Circle *cir = (Circle *)src;
			return new Circle(*cir);
		}
		else {
			return new Circle;
		}
	}
};
Circle Circle::circle;
