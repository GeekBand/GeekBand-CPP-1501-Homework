#ifndef RECTANGLE_H
#define RECTANGLE_H
class Shape
{

	int no;
};
class Point
{
	int x;
	int y;
};
class Rectangle:public Shape
{
	int width;
	int height;

	Point *leftUp;
public:
	Rectangle(int width,int height);
	Rectangle(const Rectangle &other);
	Rectangle& operator=(const Rectangle &other);
	~Rectangle();

};

#endif
