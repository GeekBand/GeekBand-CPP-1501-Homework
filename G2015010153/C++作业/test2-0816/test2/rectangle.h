#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <iostream>
using namespace std;

namespace Geekband
{
	class Rectangle : public Shape
	{
		int width;
		int height;

		Point* leftUp;

	public:
		Rectangle();
		Rectangle(int width, int height, int x, int y, int no);
		Rectangle(const Rectangle& other);
		Rectangle& operator =(const Rectangle& other);

		virtual double getArea() const;
		~Rectangle();
	};

	inline Rectangle::Rectangle()
		: Shape(0), width(0), height(0), leftUp(new Point(0, 0))
	{

	}

	inline Rectangle::Rectangle(int width, int height, int x, int y, int no)
		: Shape(no), width(width), height(height), leftUp(new Point(x, y)) 
	{

	}

	inline Rectangle::Rectangle(const Rectangle& other)
		: Shape(other), width(other.width), height(other.height)
	{
		if (other.leftUp == 0) {
			this->leftUp = 0;
		} else {
			this->leftUp = new Point(*other.leftUp);
		}
	}

	inline Rectangle& Rectangle::operator =(const Rectangle& other)
	{
		if(this == &other) {
			return *this;
		}

		this->Shape::operator =(other);

		width = other.width;
		height = other.height;

		if(leftUp != 0 && other.leftUp != 0) {
			*leftUp = *other.leftUp;
		} else {
			if(leftUp == 0 && other.leftUp != 0) {
				leftUp = new Point(*other.leftUp);
			} else if(leftUp !=0 && other.leftUp == 0) {
				delete leftUp;
				leftUp = 0;
			}
		}
		
		return *this;
	}

	inline /*virtual*/ double Rectangle::getArea() const
	{
		return (double)width * (double)height;
	}

	inline Rectangle::~Rectangle()
	{
		delete leftUp;
	}
	
}

#endif