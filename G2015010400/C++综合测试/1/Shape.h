#ifndef SHAPE_H
#define SHAPE_H

class Shape 
{
public:
	Shape(int no_ = 0) : no(no_) {}
	virtual ~Shape() {}
private:
	int no;
};

#endif