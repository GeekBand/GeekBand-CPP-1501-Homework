#ifndef __SHAPE__
#define __SHAPE__

class Shape
{
private:
	int no;
	static int NO;

public:
	Shape() :no(++NO) {}
	virtual int getArea() = 0;
	virtual ~Shape() {}
};

int Shape::NO = 0;

#endif
