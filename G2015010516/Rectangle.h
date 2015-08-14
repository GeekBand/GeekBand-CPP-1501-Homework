#ifndef RECTANGLE_H
#define RECTANGLE_H
class Shape
{

	int no;

public:
	void setNo(int no);
	int getNo() const;
};
class Point
{
private:
	int x;
	int y;
public:
	Point(int inputX,int inputY);
	int getX() const;
	int getY() const;
	void setX(int);
	void setY(int);


};
class Rectangle:public Shape
{
	int width;
	int height;

	Point *leftUp;
public:
	Rectangle(int width,int height,int x,int y);
	Rectangle(const Rectangle &other);
	Rectangle& operator=(const Rectangle &other);
	~Rectangle();

	int getWidth() const;
	int getHeight() const;
	void setWidth(int);
	void setHeight(int);
	Point* getLeftUp() const;	

};

#endif
