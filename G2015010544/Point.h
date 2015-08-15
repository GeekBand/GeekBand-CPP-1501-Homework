#ifndef __POINT__
#define __POINT__

class Point
{

private:
	int x;
	int y;

public:
	Point(int p_x, int p_y): x(p_x), y(p_y){}

	int getPointX(void) const { return this->x; } 
	int getPointY(void) const { return this->y; }
};


#endif