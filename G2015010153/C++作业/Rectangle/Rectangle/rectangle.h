#ifndef __RECTANGEL__
#define __RECTANGEL__

#include <iostream>
#include "shape.h"
#include "point.h"

using namespace std;

namespace shape
{

	class Retangle;

	class Rectangle: public shape {
		int width;
		int height;

		Point *leftUp;

	public:
		Rectangle();
		Rectangle(int width, int height, int x, int y);
		Rectangle(const Rectangle& other);
		Rectangle& operator =(const Rectangle& other);
		~Rectangle();

		// for test
		void set_leftup(Point* leftUp);
		Point* get_leftup() const;

		friend ostream& operator << (ostream& os, const Rectangle& rtl);
	};

	inline
		Rectangle::Rectangle()
		: width(0), height(0), leftUp(new Point(0, 0))
	{ }

	inline
	Rectangle::Rectangle(int width, int height, int x, int y)
		: width(width), height(height), leftUp(new Point(x, y))
	{ }

	inline
	Rectangle::Rectangle(const Rectangle& other)
		: width(other.width), height(other.height)
	{

		if(other.leftUp == NULL) { // nullptr
			leftUp = NULL; // nullptr
		} else {
			leftUp = new Point(other.leftUp->X(), other.leftUp->Y());
		}
	}

	inline
	Rectangle& Rectangle::operator =(const Rectangle& other) {
		// check self assignment
		if(this == &other) {
			return *this;
		}

		shape::operator = (other);

		width = other.width;
		height = other.height;

		if(other.leftUp == NULL) { // nullptr
			if(leftUp != NULL) {
				delete leftUp;
				leftUp = NULL;
			}
		} else {
			if(leftUp == NULL) {
				leftUp = new Point(other.leftUp->X(), other.leftUp->Y());
			} else {
				leftUp->X(other.leftUp->X());
				leftUp->Y(other.leftUp->Y());
			}
		}

		return *this;
	}


	inline
	void Rectangle::set_leftup(Point* leftUp) {
		if(this->leftUp != NULL) { // nullptr
			delete this->leftUp;
		}
		this->leftUp = leftUp;
	}
	
	inline
	Point* Rectangle::get_leftup() const {
		return this->leftUp;
	}

	inline
	Rectangle::~Rectangle() {
		if(leftUp != NULL) { // nullptr
			delete leftUp;
		}
	}

	ostream& operator << (ostream& os, const Rectangle& rtl) {
		if(rtl.get_leftup() == NULL) {
			return cout << "[width : " << rtl.width << ", height : " << rtl.height << ", leftUp : NULL]";
		}
		return cout << "[width : " << rtl.width << ", height : " << rtl.height <<
			", leftUp : [x : " << rtl.leftUp->X() << ", y : " << rtl.leftUp->Y() << "]]";
	}

}


#endif
