#ifndef _shape_
#define _shape_

#include<iostream>

class Shape{
private:
	int no;
public:
	virtual int getArea()const = 0;
	virtual void detail()const = 0;// 提供调试用，可以输出自己的成员信息
	virtual ~Shape(){};
};

class Point{
private:
	int x;
	int y;
public:
	void setX(int x){
		this->x = x;
	}
	void setY(int y){
		this->y = y;
	}
	Point(int _x = 0, int _y = 0) :x(_x), y(_y){}
};

class Rectangle :public Shape{
private:
	int width;
	int height;
	Point leftUp;
public:
	virtual int getArea()const override{
		return width*height;
	}
	virtual void detail()const override{
		std::cout << "w:" << width << "  h:" << height << std::endl;
	}
	void setW(int w){
		width = w;
	}
	void setH(int h){
		height = h;
	}
	Rectangle(int w = 0, int h = 0, int x = 0, int y = 0) :width(w), height(h), leftUp(Point(x, y)){}
};

class Circle :public Shape{
private:
	Point center;
	int radius;
public:
	virtual int getArea()const override{
		return 3.1415926*radius*radius;
	}
	virtual void detail()const override{
		std::cout << "radius:" << radius << std::endl;
	}
	Circle(int r = 0, int x = 0, int y = 0) :radius(r), center(Point(x, y)){}
};
#endif