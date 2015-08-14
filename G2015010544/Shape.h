#ifndef __SHAPE__
#define __SHAPE__

class Shape
{

private:
	int no;

public:
	Shape (int n = 0): no (n){ }  //Constructor
	getShapeNo (void) const { return this->no; }
};


#endif