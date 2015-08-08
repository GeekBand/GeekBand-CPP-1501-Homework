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
		Rectangle(int width, int height, int x, int y);
		Rectangle(const Rectangle& other);
		Rectangle& operator =(const Rectangle& other);
		~Rectangle();

		friend ostream& operator << (ostream& os, const Rectangle& rtl); 
	};

	inline
	Rectangle::Rectangle(int width, int height, int x, int y) 
		: width(width), height(height), leftUp(new Point(x, y))
	{ }

	inline
	Rectangle::Rectangle(const Rectangle& other) {
		width = other.width;
		height = other.height;

		leftUp->X(other.leftUp->X());
		leftUp->Y(other.leftUp->Y());
	}

	inline
	Rectangle& Rectangle::operator =(const Rectangle& other) {
		// check self assignment
		if(this == &other) {
			return *this;
		}

		width = other.width;
		height = other.height;
		
		leftUp->X(other.leftUp->X());
		leftUp->Y(other.leftUp->Y());

		return *this;
	}

	inline
	Rectangle::~Rectangle() {
		delete leftUp;
	}

	ostream& operator << (ostream& os, const Rectangle& rtl) {
		return cout << "[width : " << rtl.width << ", height : " << rtl.height << 
			", leftUp : [x : " << rtl.leftUp->X() << ", y : " << rtl.leftUp->Y() << "]]";
	}

}


#endif