#ifndef __SHAPE__
#define __SHAPE__
#include <iostream>
using std::ostream;
using std::endl;

//Shape
class Shape {
	int number;
	static unsigned NumberCounter;
public:
	int ID()const { return number; }
	Shape(): number(NumberCounter++){}
	virtual ~Shape() = default;
};
unsigned Shape::NumberCounter = 0;



//Point
class Point {
public:
	Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
public:
	int x, y;
};



//Rectangle
class Rectangle :public Shape {

private://Field
	int width, height;
	Point *Pt_leftUp;

private://Help Methon
	friend Rectangle& do_RectangleCopy(Rectangle *dest, const Rectangle& src) {
		if (dest == NULL) {
			dest = new Rectangle;
		}
		if (dest == &src) {
			return *dest;
		}
		dest->width = src.width;
		dest->height = src.height;

		if (src.Pt_leftUp != nullptr) {
			if (dest->Pt_leftUp == nullptr) {
				dest->Pt_leftUp = new Point;
			}
			*dest->Pt_leftUp = *src.Pt_leftUp;
		}
		else {
			if (dest->Pt_leftUp != nullptr) {
				delete dest->Pt_leftUp;
				dest->Pt_leftUp = nullptr;
			}
		}

		return *dest;
	}
	ostream& print_Rectangle(ostream& os) const {
		os << "the rect widht:" << this->Width() << " height:" << this->Height() << endl;
		return os;
	}

public://Constructor & operator
	Rectangle(int w = 0, int h = 0, int _x = 0, int _y = 0);
	Rectangle(const Rectangle& cp);
	Rectangle& operator =(const Rectangle& cp);
	virtual ~Rectangle();

	friend ostream& operator <<(ostream& os, const Rectangle& rect) {
		return rect.print_Rectangle(os);
	}

public://Property
	int Width()const {
		return width;
	}
	int Height()const {
		return height;
	}
	void set_Widht(int w) {
		width = w;
	}
	void set_Height(int h) {
		height = h;
	}
};


inline Rectangle::Rectangle(int w, int h, int _x, int _y) :
	width(w), height(h), Pt_leftUp(new Point(_x, _y)) {}

inline Rectangle::Rectangle(const Rectangle & cp) :
	Rectangle(cp.width, cp.height) {
	if (cp.Pt_leftUp != nullptr) {
		Pt_leftUp = new Point(*cp.Pt_leftUp);
	}
}

inline Rectangle & Rectangle::operator=(const Rectangle & cp) {
	return do_RectangleCopy(this, cp);
}

inline Rectangle::~Rectangle() {
	delete Pt_leftUp;
}

#endif
