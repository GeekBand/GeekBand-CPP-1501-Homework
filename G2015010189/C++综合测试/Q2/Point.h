#ifndef __POINT__
#define __POINT__

class Point
{
protected:
	int x;
	int y;
public:
	Point(int x, int y):x(x),y(y){}
	int GetX() const{return x;}
	int GetY() const{return y;}
	void SetX(int a)
	{
		x = a;	
	}
	void SetY(int b)
	{
		y = b;		
	}
};


#endif