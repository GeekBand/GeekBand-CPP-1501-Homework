#ifndef _SHAPE_H_
#define _SHAPE_H_
class Shape
{
public:
	//���캯���еĲ��������֣���Ҫ���Ա������������ͬ
	Shape(int _no = 0): no(_no) {};
	virtual ~Shape();

private:
	int no;
};

#endif // _SHAPE_H_
