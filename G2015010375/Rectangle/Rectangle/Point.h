#ifndef __PONIT__
#define __PONIT__

class Point
{
public:
	Point(int x = 0, int y = 0) :x(x), y(y)
	{
	}

	Point(const Point &p);
	~Point();

	int getX() const { return x; }
	int getY() const { return y; }

private:
	int x, y;
};

#endif

inline
Point::Point(const Point &p)
{
	this->x = p.x;
	this->y = p.y;
}

inline 
Point::~Point()
{
}
