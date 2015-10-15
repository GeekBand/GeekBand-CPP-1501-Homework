#ifndef _RECTANGLE_
#define _RECTANGLE_

class Shape{
private:
	int no;
public:
	Shape(int _no = 0) :no(_no){}
	virtual ~Shape(){}
};

class Point{
private:
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) :x(_x), y(_y){}
};

class Rectangle :public Shape{
private:
	int width;
	int height;
	Point *leftUp;
public:
	Rectangle(int _width = 0, int _height = 0, int _x = 0, int _y = 0, int _no = 0) :width(_width), height(_height), leftUp(new Point(_x, _y)), Shape(_no){
		// 构造函数
	}
	Rectangle(const Rectangle& other) :Shape(other),width(other.width), height(other.height), leftUp(new Point(*other.leftUp)){
		// 拷贝构造函数
	}
	Rectangle& operator=(const Rectangle& other){
		//　重载赋值运算符
		if (this == &other){
			return *this;
		}
		else{
			this->width = other.width;
			this->height = other.height;
			delete this->leftUp;
			this->leftUp = new Point(*other.leftUp);
			Shape::operator=(other);
			return *this;
		}
	}
	~Rectangle(){
		delete leftUp;
		leftUp = nullptr;
	}
};

#endif
