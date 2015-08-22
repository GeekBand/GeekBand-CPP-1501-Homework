#ifndef __POINT__
#define __POINT__

namespace Geekband
{
	class Point;

	class Point
	{
		int x;
		int y;
	public:
		// 没必要写，编译器自动生成
		// Point() : x(0), y(0) {}
		Point(int x, int y) : x(x), y(y) {}
		
		int X() { return x; }
		void X(int x) { this->x = x; }
		int Y() { return y; }
		void Y(int y) { this->y = y; }

		//friend class Rectangle;
	};

}

#endif