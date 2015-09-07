#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

class Shape
{
	int no;
	
public:
	Shape():no(0){}
public:
	//no
	int No() const { return no; }
	void No(int val) { no = val; }

};
class Point
{
	int x;	
	int y;
	
public:
	Point(int xPos,int yPos):x(xPos),y(yPos){}
public:
	//y
	int Y() const { return y; }
	void Y(int val) { y = val; }
	//x
	int X() const { return x; }
	void X(int val) { x = val; }


};
class Rectangle :
	public Shape
{
	int width;	
	int height;	
	Point * leftUp;
	
public:
	Rectangle(int width, int height, int x, int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle(void);
public:
	//leftUp
	Point * LeftUp() const { return leftUp; }
	void LeftUp(Point * val) { leftUp = val; }
	//height
	int Height() const { return height; }
	void Height(int val) { height = val; }
	//width
	int Width() const { return width; }
	void Width(int val) { width = val; }
};
#endif