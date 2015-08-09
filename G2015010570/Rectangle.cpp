#include "Rectangle.h"

Rectangle::Rectangle(int width, int height, int x, int y, int no):Shape(no) {
	this->width = width;
	this->height = height;
	this->leftUp = new Point(x, y);
}

Rectangle::~Rectangle() {
	delete leftUp;
}

Rectangle::Rectangle(const Rectangle& other):Shape(other.no) {
	this->width = other.width;
	this->height = other.height;
	this->leftUp = new Point(other.getX(), other.getY());
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
	if (this == &other) {
		return *this;
	}
	this->width = other.width;
	this->height = other.height;
	delete this->leftUp;
	this->leftUp = new Point(other.getX(), other.getY());
	return *this;
}

void Rectangle::setHeight(int height) {
	this->height = height;
}

int Rectangle::getHeight() const {
	return this->height;
}

void Rectangle::setWidth(int width) {
	this->width = width;
}

int Rectangle::getWidth() const {
	return this->width;
}

void Rectangle::setX(int x) {
	this->leftUp->setX(x);
}
int Rectangle::getX() const {
	return this->leftUp->getX();
}
void Rectangle::setY(int y) {
	this->leftUp->setY(y);
}
int Rectangle::getY() const {
	return this->leftUp->getY();
}

