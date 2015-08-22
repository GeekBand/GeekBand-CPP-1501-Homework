#include "Rectangle.h"
#include "Circle.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

static const short RANDOM_MIN = 1;
static const short RANDOM_MAX = 10;

static const short RANDOM_MOD = RANDOM_MAX - RANDOM_MIN + 1;

static const short ARRAY_LENGTH = 20;

int getRandom();
void filterIfAreaLessThan(int area, Shape** shapes, int length);

int main(int argc, char** argv) {

	Shape** shapes = new Shape*[ARRAY_LENGTH];

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {
		shapes[i] = new Rectangle(i, getRandom(), getRandom(), getRandom(),
				getRandom());
	}
	for (int i = 10; i < 20; i++) {
		shapes[i] = new Circle(i, getRandom(), getRandom(), getRandom());
	}

	filterIfAreaLessThan(50, shapes, ARRAY_LENGTH);

	for (int i = 0; i < 20; i++) {

		if (shapes[i] != NULL) {

			cout << "no=" << shapes[i]->getNo() << ",area="
					<< shapes[i]->getArea() << endl;

			delete shapes[i];
			shapes[i] = NULL;
		}
	}
	delete[] shapes;

	return 0;
}

inline int getRandom() {
	return rand() % RANDOM_MOD + RANDOM_MIN;
}

void filterIfAreaLessThan(int area, Shape** shapes, int length) {
	for (int i = 0; i < length; i++) {
		if (shapes[i] != NULL && shapes[i]->getArea() < area) {
			delete shapes[i];
			shapes[i] = NULL;
		}
	}
}
