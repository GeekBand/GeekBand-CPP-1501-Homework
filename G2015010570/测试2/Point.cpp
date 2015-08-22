#include "Point.h"

Point::Point(int x, int y) :
		x(x), y(y) {
}

Point::~Point() {
}

void Point::setX(int x) {
	this->x = x;
}

int Point::getX() const {
	return this->x;
}

void Point::setY(int y) {
	this->y = y;
}

int Point::getY() const {
	return this->y;
}
