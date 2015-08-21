#ifndef _GetArea_
#define _GetArea_

class Shape
{
public:
	Shape(int _no = 0):no(_no) {  }
	virtual ~Shape() {}
	virtual double getArea()  = 0;
	int getNo() { return no; }
private:
	int no;
};

class Point
{
public:
	Point(int _x = 0,int _y = 0):x(_x),y(_y) {}
	virtual ~Point() {}
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	int getX() { return x; }
	int getY() { return y; }

private:
	int x;
	int y;
};

class Rectangle:public Shape
{
public:
	Rectangle(int _no,int _width,int _height,int _x, int _y);
	~Rectangle() {}	
	double getArea();
private:
	int width;
	int height;
	Point leftUp;
};

Rectangle::Rectangle(int _no = 0,int _width = 0,int _height = 0,int _x = 0,int _y = 0) : Shape(_no),width(_width),height(_height)
{
	leftUp.setX(_x);
	leftUp.setY(_y);
}

inline
double Rectangle::getArea()
{
	return 1.0*width*height;
}

const double PI = 3.141592652;

class Circle:public Shape
{
public:
	Circle(int _no,int _radius,int _x,int _y);
	~Circle() {}
	double getArea();
private:
	Point center;
	int radius;
};

inline
Circle::Circle(int _no,int _radius = 0,int _x = 0,int _y = 0):Shape(_no),radius(_radius)
{
	center.setX(_x);
	center.setY(_y);
}

inline
double Circle::getArea()
{
	return PI*radius*radius;
}
#endif
