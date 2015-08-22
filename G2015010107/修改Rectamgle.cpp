#include <iostream>
using namespace std;


class Shape
{
private:	
	int no;
} ;

class Point
{
private:	
	int x;
	int y;
public:
	void setX(int ix);
	void setY(int iy);
	int getX();
	int getY();	 
 };
inline void
Point::setX(int ix){x=ix;} 
inline void
Point::setY(int iy){y=iy;} 
inline int
Point::getX(){return x;}
inline int
Point::getY(){return y;} 
 
class Rectamgle:public Shape
{
private:	
	int width;
	int height;
	Point* leftUP;
public:
	Rectamgle(int width,int height, int x, int y);
	Rectamgle(const Rectamgle& other);
	Rectamgle& operator =(const Rectamgle& other);
	~Rectamgle();	
	int getWidth();
	int getHeight();
};
int
Rectamgle::getWidth()
{
	return width;
}

int
Rectamgle::getHeight()
{
	return height;
}

Rectamgle::Rectamgle(int width,int height, int x, int y)
		: width(width), height(height)
	{ 
		leftUP = new  Point();
		leftUP->setX(x);
		leftUP->setY(y);
		
	}
Rectamgle::Rectamgle(const Rectamgle& other)
{

		this->height= other.height;
		this->width = other.width;
		delete leftUP;
		this->leftUP = new  Point();
		this->leftUP->setX(other.leftUP->getX());
		this->leftUP->setY(other.leftUP->getY());
		
}
Rectamgle& 
Rectamgle::operator =(const Rectamgle& other)
{
	if(this!=&other){
		this->height= other.height;
		this->width = other.width;
		delete leftUP;
		this->leftUP = new  Point();
		this->leftUP->setX(other.leftUP->getX());
		this->leftUP->setY(other.leftUP->getY());
		return *this;
	}else{
		return *this;
	}	
		
}	
Rectamgle::~Rectamgle()
{
	delete leftUP;
}



int main()
{
	Rectamgle r1(10,5,2,2);
	Rectamgle r2(r1);
	Rectamgle r3=r2;
	cout << "矩形1的宽:" << r1.getWidth() <<
			"矩形1的高:"  << r1.getHeight() << endl;
			 
	cout << "矩形2的宽:" << r2.getWidth() <<
			"矩形2的高:"  << r2.getHeight() << endl;
			
	cout << "矩形3的宽:" << r3.getWidth() <<
			"矩形3的高:"  << r3.getHeight() << endl;		
	return 0;
}






















