#ifndef _SHAPE_H_
#define _SHAPE_H_
class Shape
{
public:
	//构造函数中的参数的名字，不要与成员变量的名字相同
	Shape(int _no = 0): no(_no) {};
	virtual ~Shape();

private:
	int no;
};

#endif // _SHAPE_H_
