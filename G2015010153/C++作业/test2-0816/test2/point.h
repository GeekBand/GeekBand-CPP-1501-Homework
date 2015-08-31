#ifndef _POINT_H_
#define _POINT_H_

namespace Geekband
{
	class Point
	{
		int x;
		int y;


	public:
		Point(int x = 0, int y = 0) : x(x), y(y) {}

		int getX() const { return x; }
		void setX(int x) { this->x = x; }
		int getY() const { return y; }
		void setY(int y) { this->y = y; }
	};

}

#endif