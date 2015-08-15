//为下面的Rectangle类实现构造函数，拷贝构造函数，赋值操作符，析构函数。
#ifndef  __MYRECTANGLE__
#define  __MYRECTANGLE__

class Shape
{
public:
	Shape():no(0){}

private:
	int no;
};

class Point
{
public:
	Point() :x(0), y(0){}
	Point(const int x, const int y) :x(x), y(y){}

public:
	int x;
	int y;
};

class Rectangle : public Shape
{
private:
	int width;
	int height;

	Point* leftUp;

public:
	Rectangle(int width, int height, int x, int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator =(const Rectangle& other);
	~Rectangle();
	
	const int GetWidth() const { return width; }
	const int GetHeight() const { return height; }
	const Point GetStartPoint() const { return *leftUp; }
	void SetWidth(const int width) { this->width = width; }
	void SetHeight(const int height) { this->height = height; }
	void SetStartPoint(const Point &leftUp) { this->leftUp->x = leftUp.x; this->leftUp->y = leftUp.y; }

	void PrintDetail() const;
};

#endif
