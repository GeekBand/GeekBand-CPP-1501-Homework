#ifndef _RECTANGLE_
#define _RECTANGLE_

class Shape
{
public:
	Shape(int _no = 0) : no(_no){}
	virtual ~Shape(){}
private:
	int no;
};

class Point
{
public:
	Point(int _x = 0, int _y = 0) : x(_x),y(_y){}
private:
	int x;
	int y;
};

class Rectangle:public Shape
{
public:
	Rectangle(int _width,int _height,int _x,int _y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();
private:
	int width;
	int height;
	Point* leftUp;
};

Rectangle::Rectangle(int _width = 0,int _height = 0,int _x = 0,int _y = 0):width(_width),height(_height),leftUp(new Point(_x,_y))
{
}

Rectangle::Rectangle(const Rectangle& other):Shape(other),width(other.width),height(other.height)
{
	if(other.leftUp != nullptr)
	{
		leftUp = new Point(*other.leftUp);
	}else
	{
		leftUp = nullptr;
	}
}
Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if(this != &other)
	{
		Shape::operator=(other);
		width = other.width;
		height = other.height;
		if(leftUp != nullptr)
		{
			if(other.leftUp != nullptr)
			{
				*leftUp = *other.leftUp;
			}else
			{
				delete leftUp;
				leftUp = nullptr;
			}
		}else
		{
			if(other.leftUp != nullptr)
			{
				leftUp = new Point(*other.leftUp);
			}
		}
	}

	return *this;
}
Rectangle::~Rectangle()
{
	delete leftUp;
	leftUp = nullptr;
}
#endif
