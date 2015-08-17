#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include "point.h"

class Rectangle;

class Rectangle: public Shape
{
public:
	Rectangle(const int width = 0, const int height = 0, const int x = 0, const int y = 0, const int no = 0) : 
		Shape(no), width_(width), height_(height), leftUp(new Point(x, y)) {} // explict call base class's ctr
	Rectangle(const Rectangle& other_rectangle);
	Rectangle& operator= (const Rectangle& other_rectangle);
	~Rectangle();
	int width() const { return this->width_; }
	void set_width(const int width) { this->width_ = width; }
	int height() const { return width_; }
	void set(const int height) { this->height_ = height; }
	Point* get_leftUp() const { return this->leftUp; };
	void set_leftUP(const Point& other_point) { *this->leftUp = other_point;}

private:
	int width_;
	int height_;
	Point* leftUp;
};


inline
	Rectangle::Rectangle( const Rectangle& other_rectangle ) : 
	    Shape(other_rectangle), height_(other_rectangle.height_), width_(other_rectangle.width_) 
		// use initialization list if member is not a pointer
		// explict call base class's copy ctr
{
	if ( other_rectangle.leftUp != nullptr ) { // check a pointer is nullptr or not before you use it. E2.1 
		// call the copy  assignment function is good for encapsulation. E.12 copy all parts of an object
		leftUp = new Point( *other_rectangle.leftUp ); 
	}
	else {
		this->leftUp = nullptr; // leftUp need to be initialized, otherwise it will be a "wild pointer", which may cause undefined behavior
		std::cerr << "Copy is Failed! Other Rectangle' leftUp pointer is NULL!" << std::endl;
	}
}

inline Rectangle&
	Rectangle::operator= (const Rectangle& other_rectangle)
{
	if ( this != &other_rectangle ) {
		if ( other_rectangle.leftUp != nullptr ) { 
			Point* leftUp_origin = this->leftUp; // copy leftUp before it is deleted for the case that new expression is failed and throw exception
			this->leftUp = new Point(*other_rectangle.leftUp); // excepetion safety also cause self-assignment safety
			delete leftUp_origin; //if new expression success, delete the copy of leftUp
			this->Shape::operator=(other_rectangle); // explict call base class's operator= 
			this->width_ = other_rectangle.width_;
			this->height_ = other_rectangle.height_;
		}
		else {
			this->leftUp = nullptr;
			std::cerr << "Copy is Falied! Other Rectangle' leftUp pointer is NULL!" << std::endl;
		}
	}
	return *this;
}

#include <iostream>

inline
	Rectangle::~Rectangle()
{
	delete this->leftUp; 
	// delete a pointer and then assign nullptr to it 
	this->leftUp = nullptr;
	std::cout << "Rectangle Destructed!" << std::endl;
}

inline std::ostream&
	operator<< ( std::ostream& os, const Rectangle& rectangle )
{
	os << "This is a rectangle" << std::endl 
		<< "No:" << rectangle.no()
        << " Width: " << rectangle.width() << " Height: " << rectangle.height()
		<< " LeftUp: " << *rectangle.get_leftUp() << std::endl; 
	return os;
}

#endif