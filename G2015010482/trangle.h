#ifndef _trangle
#define _trangle
#include <iostream>
using namespace std;
class Shape
{
	int no;
};

class Point
{
	int x;
	int y;
public:
	Point(int inputX = 0,int inputY = 0):x(inputX),y(inputY){}
	int getX() const{return x;}
	int getY() const{return y;}
};

class Rectangle: public Shape
{
	int width;
	int height;
	Point * leftUp;
	public:
		Rectangle(int width, int height, int x, int y);
		Rectangle(const Rectangle& other);
		Rectangle& operator=(const Rectangle& other);
		~Rectangle();
		int getWidth () const{return width;}
		int getHeight() const{return height;}
		void printPoint() const{cout<<" x="<< leftUp->getX() <<" y="<< leftUp->getY()<<"\n";}

};
Rectangle:: Rectangle(int width, int height, int x, int y)
{
	this->width = width;
	this->height = height;
	this->leftUp = new Point(x,y);
}

Rectangle :: Rectangle(const Rectangle& other)
{
	this->width = other.width;
	this->height = other.height;
	this->leftUp = new Point;
	*this->leftUp = *other.leftUp;
}

Rectangle& Rectangle :: operator=(const Rectangle& other)
{
	this->width = other.width;
	this->height = other.height;
	*this->leftUp = *other.leftUp;
	return *this;
}
Rectangle :: ~Rectangle()
{
	delete leftUp;
}
#endif