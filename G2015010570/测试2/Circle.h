#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"
#include "Point.h"

class Circle: public Shape {
public:
	Circle(int no, int x, int y, int radius);
	virtual ~Circle();

	void setRadius(int radius);
	int getRadius() const;

	int getArea() const;

	void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;


private:
	Point* center;
	int radius;
};

#endif
