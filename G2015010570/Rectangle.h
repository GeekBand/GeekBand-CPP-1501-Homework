#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"
#include "Point.h"

class Rectangle: public Shape {
public:
	Rectangle(int width, int height, int x, int y,int no);
	virtual ~Rectangle();
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);

	void setHeight(int height);
	int getHeight() const;

	void setWidth(int width);
	int getWidth() const;

	void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;
private:
	int width;
	int height;
	Point* leftUp;
};

#endif
