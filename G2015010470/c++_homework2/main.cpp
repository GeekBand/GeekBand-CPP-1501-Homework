#include <random>
#include <iostream>
#include "Shape.h"

int main() {
	Shape **shapes = new Shape*[20];
	
	// create default engine as source of randomness
	std::default_random_engine e;

	// use engine to generate integral numbers between 1 and 10 (both included)
	std::uniform_int_distribution<int> u(1, 20);

	// create 10 regtangle random
	for (size_t i = 0; i != 10; ++i) {
		int rectX = u(e), rectY = u(e);
		int rectWidth = u(e), rectHeight = u(e);
		shapes[i] = new Rectangle(i, rectX, rectY, rectWidth, rectHeight);
	}

	// create 10 circle random
	for (size_t i = 10; i != 20; ++i) {
		int circleX = u(e), circleY = u(e);
		int radius = u(e);
		shapes[i] = new Circle(i, circleX, circleY, radius);
	}

	// remove shape that its area less than 50
	int numDeleted = 0;
	for (size_t i = 0; i != 20; ++i) {
		if (shapes[i]->getArea() < 50) {
			delete shapes[i];
			shapes[i] = nullptr;
			++numDeleted;
		}
	}

	// crate new area to store shape that area equal or greater than 50
	const size_t size = 20 - numDeleted;
	Shape **shapesAccepted = new Shape*[size];
	for (size_t i = 0, j = 0; i != 20; ++i) {
		if (shapes[i] != nullptr) {
			shapesAccepted[j++] = shapes[i];
		}
	}

	// print all shape in shapesAccepted array
	for (size_t i = 0; i != size; i++) {
		std::cout << *shapesAccepted[i] << std::endl;
	}

	delete[] shapes;
	for (size_t i = 0; i != size; ++i) {
		delete shapesAccepted[i];
	}
	delete[] shapesAccepted;

	return 0;
}