#ifndef _SHAPE_H_
#define _SHAPE_H_

class Shape
{
public:
	Shape(): no(++NO) {}
	virtual ~Shape() {}

	virtual double getArea() const = 0;


private:
	int no;
	static int NO;
};

int Shape::NO = 0;

#endif // _SHAPE_H_
