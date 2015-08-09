#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {

public:
	Shape(int no);
	virtual ~Shape();
	void setNo(int no);
	int getNo() const;
protected:
	int no;
};

#endif
