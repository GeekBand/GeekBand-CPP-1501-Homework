#include <iostream>
using namespace std;

#ifndef __RECTANGLE__
#define __RECTANGLE__

class Shape
{
public:
	Shape(const int _no = 0) : no(_no){}
	int getNo(){return no;}
private:
	int no;
};

class Point
{
public:
	Point(const int _x = 0,const int _y = 0) : x(_x),y(_y){}
	int getX() {return x;};
	int getY() {return y;}
private:
	int x;
	int y;
};

class Rectangle : public Shape
{
public:
	Rectangle(int width,int height,int x,int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();
	void showInfo();
private:
	int width;
	int height;
	Point* leftUp;
};

inline Rectangle::Rectangle(int width,int height,int x,int y)
{
	this->width = width;
	this->height = height;
	leftUp = new Point(x,y);
}

inline Rectangle::Rectangle(const Rectangle& other)
{
	width = other.width;
	height = other.height;
	leftUp = new Point(other.leftUp->getX(),other.leftUp->getY());
}

inline Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if(this == &other)
	{
		return *this;
	}
	
	delete leftUp;

	leftUp = new Point(other.leftUp->getX(),other.leftUp->getY());
	width = other.width;
	height = other.height;

	return *this;
}

inline Rectangle::~Rectangle()
{
	delete leftUp;
}

inline void Rectangle::showInfo()
{
	cout<<"width = "<<width<<endl;
	cout<<"height= "<<height<<endl;
	cout<<"leftUp->getX() = "<<leftUp->getX()<<endl;
	cout<<"leftUp->getY() = "<<leftUp->getY()<<endl;
	cout<<"no = "<<getNo()<<endl;
}
#endif
