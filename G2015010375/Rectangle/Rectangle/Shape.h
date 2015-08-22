#ifndef __SHAPE__
#define __SHAPE__

class Shape
{
public:
	Shape(int no = 0) :no(no)
	{
	}

	virtual ~Shape() {}

private:
	int no;
};

#endif
