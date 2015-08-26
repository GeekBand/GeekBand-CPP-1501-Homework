#pragma once
constexpr double M_PI = 3.1415926535897932384626433832795;

class Shape {
	static Shape *shape_properties[];
	static int counter;
public:
	static Shape *findAndClone(int type, Shape *src = nullptr) {
		for (int i = 0; i != 2; ++i) {
			if (type == shape_properties[i]->getType()) {
				return shape_properties[i]->clone(src);
			}
		}
		return nullptr;
	}
protected:
	int no;
	static void add_property(Shape *proper) {
		if (counter <= 1) {
			shape_properties[counter++] = proper;
		}
	}
public:
	virtual int getArea() = 0;
	virtual int getType() = 0;
	virtual Shape* clone(Shape *src = nullptr) = 0;
	virtual ~Shape() = default;
};
Shape *Shape::shape_properties[2];
int Shape::counter = 0;

class Point {

	int x, y;
public:
	Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
};

