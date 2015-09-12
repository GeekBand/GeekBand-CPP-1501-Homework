#ifndef _POINT_H_
#define _POINT_H_
class Point
{
public:
	//构造函数中的参数的名字，不要与成员变量的名字相同
	Point(int _x = 0, int _y = 0): x(_x), y(_y) {};
private:
	int x;
	int y;
};

#endif // _POINT_H_
