#ifndef __SHAPE__
#define __SHAPE__

class Shape{
private:
	int no;
public:
	Shape(){}
	Shape(int _no) :no(_no){}
	virtual ~Shape(){}
};

#endif