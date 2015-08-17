#ifndef SHAPE_H
#define SHAPE_H

class Shape;

class Shape
{
public:
	Shape(int no = 0) : no_(no) {} //class without pointer: use default big three
	virtual ~Shape() {}

	int no() const { return no_;}
	void set_no(const int no) { no_ = no; }
private:
	int no_;
};



#endif