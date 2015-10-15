#ifndef _MYRECTANGLE_
#define _MYRECTANGLE_

class Point
{
public:
	Point(int _x=0,int _y=0)
	{
		x = _x;
		y = _y;
	}

	int x;
	int y;
};

class Rectangle:public Point
{
public:
	 int width ;
     int height;

     Point * leftUp;
     Point * rightDown;

     Rectangle(int width, int height, int x, int y);
     Rectangle(const Rectangle& other);
     Rectangle& operator=(const Rectangle& other);
     ~Rectangle();
};

inline 
Rectangle::Rectangle(int width,int height,int x,int y)
{
	int _x = x;
	int _y = y;
	int _height = height;
	int _width = width;

	leftUp = new Point(_x,_y);

	rightDown = new Point(_x+width,_y+height);

};

inline
Rectangle::Rectangle(const Rectangle& other)
{
	width = other.width;
	height = other.height;
	leftUp = new Point(other.leftUp->x,other.leftUp->y);

	rightDown = new Point(other.rightDown->x,other.rightDown->y);
	
};

inline
Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if(this == &other)
		return *this;

	delete leftUp;
	leftUp = new Point(other.leftUp->x,other.leftUp->y);

	delete rightDown;
	rightDown = new Point(other.rightDown->x,other.rightDown->y);
	return *this;
};

inline
Rectangle::~Rectangle()
{
	delete leftUp;
	delete rightDown;
};

#endif