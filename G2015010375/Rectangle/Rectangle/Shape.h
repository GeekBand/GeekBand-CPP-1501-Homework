#ifndef __SHAPE__
#define __SHAPE__

class Shape
{
public:
	Shape(int no = 0) :no(no)
	{
	}

	~Shape();

	int getNo() const { return no; }

	virtual void setNo(int no) { this->no = no; }

private:
	int no;
};

#endif

inline
Shape::~Shape()
{
}
