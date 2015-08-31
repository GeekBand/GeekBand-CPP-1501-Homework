#include "Rectangle.h"

Rectangle::Rectangle(int no, int width, int height, int x, int y) :
		Shape(no), width(width), height(height), leftUp(new Point(x, y)) {
}

Rectangle::~Rectangle() {
	delete leftUp;
}

Rectangle::Rectangle(const Rectangle& other) :
		Shape(other.no), width(other.width), height(other.height), leftUp(
				new Point(other.getX(), other.getY())) {

}

Rectangle& Rectangle::operator=(const Rectangle& other) {
	if (this == &other) {
		return *this;
	}
	this->no = other.no;
	this->width = other.width;
	this->height = other.height;
	*this->leftUp = *other.leftUp;
	return *this;
}

int Rectangle::getArea() const {
	return this->width * this->height;
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

