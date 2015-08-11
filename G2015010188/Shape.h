#ifndef __SHAPE__
#define __SHAPE__
#include <iostream>
using std::ostream;
using std::endl;

class Shape {
	int number;
};
class Point {
public:
	Point() :x(0), y(0) {}
public:
	int x, y;
};
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

		if (dest->Pt_leftUp == NULL) {
			dest->Pt_leftUp = new Point;
		}
		dest->Pt_leftUp->x = src.Pt_leftUp->x;
		dest->Pt_leftUp->y = src.Pt_leftUp->y;

		return *dest;
	}
	ostream& print_Rectangle(ostream& os) {
		os << "the rect widht:" << this->Width() << " height:" << this->Height() << endl;
		return os;
	}

public://Constructor & operator
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(const Rectangle& cp);
	Rectangle& operator =(const Rectangle& cp);
	~Rectangle();

	friend ostream& operator <<(ostream& os, Rectangle& rect) {
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

inline Rectangle::Rectangle() :Rectangle(0, 0) {}

inline Rectangle::Rectangle(int w, int h) : width(w), height(h) {
	Pt_leftUp = new Point;
}

inline Rectangle::Rectangle(const Rectangle & cp) {
	do_RectangleCopy(this, cp);
}

inline Rectangle & Rectangle::operator=(const Rectangle & cp) {
	return do_RectangleCopy(this, cp);
}

inline Rectangle::~Rectangle() {
	if (Pt_leftUp) {
		delete Pt_leftUp;
		Pt_leftUp = nullptr;
	}
}

#endif
