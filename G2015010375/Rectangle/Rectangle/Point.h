#ifndef __PONIT__
#define __PONIT__

class Point
{
public:
	Point(int x = 0, int y = 0) :x(x), y(y)
	{
	}


	int getX() const { return x; }
	int getY() const { return y; }

private:
	int x, y;
};

#endif

