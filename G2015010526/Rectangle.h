#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <cstdio>

class Shape 
{
public:
	explicit Shape(int no = 0) : no_(no) {}
	virtual ~Shape() {}
private:
	int no_;
};

class Point
{
public:
	Point(int x = 0, int y = 0) : x_(x), y_(y) {}
	int getX() const { return x_; }
	int getY() const { return y_; }
private:
	int x_;
	int y_;
};

class Rectangle : public Shape
{
public:
	Rectangle(int width, int height, int x, int y);
	Rectangle(const Rectangle &other);
	Rectangle& operator = (const Rectangle &other);

	~Rectangle() 
	{
		delete leftUp_;
	}

	// 测试打印数据用
	void printData() {
		printf("width = %d, height = %d, x = %d, y = %d\n", width_, height_, leftUp_->getX(), leftUp_->getY());
	}

private:
	int width_;
	int height_;
	Point* leftUp_;
};


// 普通构造
inline Rectangle::Rectangle(int width, int height, int x, int y)
: width_(width)
, height_(height)
, leftUp_(new Point(x, y))
{
}

// 拷贝构造
inline Rectangle::Rectangle(const Rectangle& other)
: width_(other.width_)
, height_(other.height_)
, leftUp_(new Point(*other.leftUp_))
{
}

// 拷贝赋值
Rectangle& Rectangle::operator = (const Rectangle& other)
{
	if (this == &other) {
		return *this;
	}
	if (leftUp_) {
		delete leftUp_;
	}
	leftUp_ = new Point(*other.leftUp_);
	width_  = other.width_;
	height_ = other.height_;
	return *this;
}

#endif