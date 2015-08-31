#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <math.h>
#include <iostream>
using namespace std;

#ifndef M_PI
# define M_PI          3.141592653589793238462643383279502884L /* pi */
#endif

namespace Geekband
{
	class Circle : public Shape
	{
		Point* center;
		int radius;

	public:
		Circle();
		Circle(int radius, int x, int y, int no);
		Circle(const Circle& other);
		Circle& operator =(const Circle& other);

		virtual double getArea() const;
		~Circle();
	};

	inline Circle::Circle() 
		: Shape(0), center(new Point(0, 0)), radius(0)
	{

	}

	inline Circle::Circle(int radius, int x, int y, int no)
		: Shape(no), center(new Point(x, y)), radius(radius)
	{

	}

	inline Circle::Circle(const Circle& other)
		: Shape(other), radius(other.radius)
	{
		if(other.center == 0) {
			center = 0;
		} else {
			center = new Point(*other.center);
		}
	}

	inline Circle& Circle::operator =(const Circle& other)
	{
		if(this == &other) {
			return *this;
		}

		this->Shape::operator =(other);
		radius = other.radius;

		if(center != 0 && other.center != 0) {
			*center = *other.center;
		} else {
			if(center == 0 && other.center != 0) {
				center = new Point(*other.center);
			} else if(center != 0 && other.center == 0) {
				delete center;
				center = 0;
			}
		}
	}

	inline /*virtual*/ double Circle::getArea() const
	{
		return M_PI * radius * radius;
	}

	inline Circle::~Circle()
	{
		delete center;
	}
}

#endif