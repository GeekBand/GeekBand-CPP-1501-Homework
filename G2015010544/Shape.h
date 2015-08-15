#ifndef __SHAPE__
#define __SHAPE__

class Shape
{

private:
	int no;

public:
	Shape (int n = 0): no (n){ }  //Constructor
	virtual int getArea() = 0;
	getShapeNo (void) const { return this->no; }
};


#endif