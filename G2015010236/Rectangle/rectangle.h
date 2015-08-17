#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include "point.h"

class Rectangle;

class Rectangle: public Shape
{
public:
	Rectangle( const int width = 0, const int height = 0, const int x = 0, const int y = 0, const int no = 0) :
		width_(width), height_(height), leftUp(new Point(x, y)) { set_no(no);}
	Rectangle(const Rectangle& other_rectangle);
	Rectangle& operator= (const Rectangle& other_rectangle);
	~Rectangle();
	int width() const { return width_; }
	void set_width(const int width) { width_ = width; }
	int height() const { return width_; }
	void set(const int height) { height_ = height; }
	Point* get_leftUp() const { return leftUp; };
	void set_leftUP(const Point& other_leftUp) { (*leftUp) = other_leftUp;}

private:
	int width_;
	int height_;
	Point* leftUp;
};

inline
	Rectangle::Rectangle(const Rectangle& other_rectangle)
{
	if (other_rectangle.leftUp != nullptr) {
		width_ = other_rectangle.width_;
		leftUp = new Point(*other_rectangle.leftUp);
	}
	else {
		std::cerr << "Copy is Failed! Other Rectangle' leftUp pointer is NULL!" << std::endl;
	}
}

inline Rectangle&
	Rectangle::operator= (const Rectangle& other_rectangle)
{
	if (this == &other_rectangle) {

	}
	else { 
		if (other_rectangle.leftUp != nullptr) { 
		    width_ = other_rectangle.width_;
		    height_ = other_rectangle.height_;
		    delete leftUp;
		    leftUp = new Point(*other_rectangle.leftUp);
		}
		else {
			std::cerr << "Copy is Falied! Other Rectangle' leftUp pointer is NULL!" << std::endl;
		}
	}
	return *this;
}

#include <iostream>

inline
	Rectangle::~Rectangle()
{
	delete leftUp;
	std::cout << "Rectangle Destructed!" << std::endl;
}

inline std::ostream&
	operator<< (std::ostream& os, const Rectangle& rectangle)
{
	os << "This is a rectangle" << std::endl 
		<< "No:" << rectangle.no()
        << " Width: " << rectangle.width() << " Height: " << rectangle.height()
		<< " LeftUp: " << *rectangle.get_leftUp() << std::endl; 
	return os;
}


#endif