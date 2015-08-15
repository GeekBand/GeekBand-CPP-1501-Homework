#include "Shape.h"

Shape::Shape(int no) {
	this->no = no;
}

Shape::~Shape() {
}

void Shape::setNo(int no) {
	this->no = no;
}

int Shape::getNo() const {
	return this->no;
}
