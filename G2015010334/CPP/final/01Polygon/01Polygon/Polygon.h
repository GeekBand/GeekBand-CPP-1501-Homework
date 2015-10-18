#pragma once
#ifndef __POLYGON_H_
#define __POLYGON_H_

class Shape {
	int no;

public:
	Shape(int input_no = 0) 
		: no( input_no ) 
	{
	}
	
	virtual ~Shape() {}

	Shape& operator = (const Shape& other) 
	{ 
		if (this == &other)
		{
			return *this;
		}
		no = other.no;
		return *this;
	}
};

class Point {
	int x;
	int y;

public:
	Point(int input_x = 0, int input_y = 0) 
		: x(input_x), 
		  y(input_y) 
	{
	}

	Point& operator = (const Point& other)
	{
		if (this == &other)
		{
			return *this;
		}

		x = other.x;
		y = other.y;

		return *this;
	}

	int X() const 
	{ 
		return x; 
	}

	int Y() const 
	{ 
		return y; 
	}
};

class Polygon : public Shape {
	Point * points;
	int		count;

public:
	Polygon(const Polygon& polygon);
	Polygon(const Point* p, int count, int no = 0);
	~Polygon();

	Polygon& operator = (const Polygon& other);

	const Point* getPoints() 
	{ 
		return points; 
	}
};

#endif

