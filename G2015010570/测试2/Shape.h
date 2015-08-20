#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {

public:
	Shape(int no);
	virtual ~Shape();
	void setNo(int no);
	int getNo() const;

	virtual int getArea() const = 0;
protected:
	int no;
};

#endif
