#include "Circle.h"

Circle::Circle(int no, int x, int y, int radius) :
		Shape(no), center(new Point(x, y)), radius(radius) {
}

Circle::~Circle() {
	delete center;
}

int Circle::getArea() const {
	return radius * radius * 3.14;
}

void Circle::setRadius(int radius) {
	this->radius = radius;
}

int Circle::getRadius() const {
	return this->radius;
}

void Circle::setX(int x) {
	this->center->setX(x);
}
int Circle::getX() const {
	return this->center->getX();
}
void Circle::setY(int y) {
	this->center->setY(y);
}
int Circle::getY() const {
	return this->center->getY();
}
