#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

class Shape
{
	int no;
};

class Point
{
	int x;
	int y;

public:
	Point(int x_, int y_) 
	{
		x = x_;
		y = y_;
	}
};

class Rectangle : public Shape
{
	int width;
	int height;

	Point* leftUp;

public:
	Rectangle(int width, int height, int x, int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();
};

inline Rectangle::Rectangle(int width, int height, int x, int y)
	: width(width), height(height), leftUp(new Point(x, y))	
{
}

inline Rectangle::Rectangle(const Rectangle& other) 
	: width(other.width), height(other.height), leftUp(new Point(*other.leftUp))	//使用编译器默认生成的Point的拷贝构造函数
{
}

inline Rectangle& Rectangle::operator = (const Rectangle& other)
{
	if (this == &other)							// 检查是否自我拷贝
	{
		return *this;
	}
	else
	{
		height = other.height;
		width = other.width;
		delete leftUp;							// 释放原有的角点资源，防止内存泄漏
		leftUp = new Point(*other.leftUp);
		return *this;
	}
}

inline Rectangle::~Rectangle()
{
	delete leftUp;
	leftUp = NULL;
}

#endif