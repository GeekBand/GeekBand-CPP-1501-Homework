#ifndef __RECTANGLE__
#define __RECTANGLE__

#include <iostream>

class Shape
{
	private:
		int no;
	public:
		Shape(int no = 0):no(no){}
};

class Point
{
	private:
		int x;
		int y;
	public:
		Point(int x=0, int y=0):x(x), y(y){}
		int get_x() const{
			return x;
		}
		int get_y() const{
			return y;
		}
};

class Rectangle: public Shape
{
	private:
		int width;
		int height;
		Point* leftUp;
	public:
		Rectangle(int, int, int, int);
		Rectangle(const Rectangle&);
		Rectangle& operator=(const Rectangle&);
		~Rectangle();

		int get_width() const{
			return width;
		}
		int get_height() const{
			return height;
		}
		int get_leftup_x() const{
			return leftUp->get_x();
		}
		int get_leftup_y() const{
			return leftUp->get_y();
		}
};

inline
std::ostream& operator<<(std::ostream&, const Rectangle&);
#endif /* __RECTANGLE__ */
