#ifndef SHAPES_H
#define SHAPES_H
#include <iostream>
class Shape;

class Shape
{
public:
	Shape(int no = 0) : no_(no) {}
	virtual ~Shape() {}
	virtual int getArea() const = 0; // pure virtual function
	virtual void outputInfo() const = 0; // pure virtual function
	int no() const { return no_;}
private:
	int no_;
};

class Point
{
public:
	Point(int x = 0, int y = 0) : x_(x), y_(y) {} // class without pointer: use default big three
	~Point() {}
	int x() const { return x_; }
	int y() const { return y_; }
private:
	int x_;
	int y_;
};

inline std::ostream&
	operator<< (std::ostream& os, const Point& point)
{
	os << "( " << point.x() << " , " << point.y() << " )";
	return os;
}

class Rectangle;

class Rectangle: public Shape
{
public:
	Rectangle( int width = 0, int height = 0, int x = 0, int y = 0, int no = 0) : 
		Shape(no), width_(width), height_(height), leftUp(Point(x, y)) {}
	// pure virtual function of base class must be realized by child class
	virtual int getArea() const { return this->height() * this->width(); }
	virtual void outputInfo() const; 

	int width() const { return this->width_; }
	int height() const { return width_; }
	Point get_leftUp() const { return leftUp; };

private:
	int width_;
	int height_;
	Point leftUp;
};


inline void
	Rectangle::outputInfo() const
{ 
	std::cout << "Rectangle " << Shape::no() << " Width: " << this->width() 
		<< " Height: " << this->height() << " Leftup: " << this->get_leftUp()
		<< " Area: " << this->getArea() << std::endl;
}

const double pi = 3.1415926;
class Circle: public Shape
{
public:
	Circle(int radius = 0, int x =0, int y = 0, int no = 0) : Shape(no), center(Point(x, y)), radius_(radius) {}
	int radius() const { return radius_; }
	Point get_center() const { return center; }
	// pure virtual function of base class must be realized by child class
	virtual int getArea() const { return  (int)(radius()*radius()* pi ); } // explicit type conversion£º double -> int
	virtual void outputInfo() const;
private:
	Point center;
	int radius_;
};

inline void
	Circle::outputInfo() const
{
	std::cout << "Circle " << Shape::no() << " Radius: " << this->radius() 
		<< " Center: " << this->get_center() << " Area: " << this->getArea() << std::endl;
}

#endif