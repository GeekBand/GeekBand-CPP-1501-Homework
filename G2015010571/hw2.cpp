#ifndef _RECTANGLE_
#define _RECTANGLE_
#include <iostream>
#include <stdlib.h>
using namespace std;
class Shape{
private:	
	int no;
public:
	Shape(int no):no(no){}
	virtual int getArea() const = 0;
	int getNo() const {return no;}
	virtual ~Shape(){}
};

class Point{
	int x;
	int y;
public:
	Point(int x, int y): x(x), y(y){}
};

class Rectangle: public Shape{
	int width;
	int height;
	Point leftUp;
public:
	Rectangle(int no, int width, int height, int x, int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	virtual int getArea() const;
	//int getNo() const {return Shape::getNo();}
	virtual ~Rectangle(){};
};

class Circle: public Shape{
	int radius;
	Point center;
public:
	Circle(int no, int radius, int x, int y);
	Circle(const Circle& other);
	Circle& operator=(const Circle& other);
	virtual int getArea() const;
	//int getNo() const {return Shape::getNo();}
	virtual ~Circle(){};
};

Rectangle::Rectangle(int no, int width, int height, int x, int y): Shape(no), width(width), height(height), leftUp(x, y){ }
Rectangle::Rectangle(const Rectangle& other): Shape(other.getNo()), width(other.width), height(other.height), leftUp(other.leftUp){ }
Rectangle& Rectangle::operator=(const Rectangle& other){
	if(this == &other){
		return *this;
	}
	this->Shape::operator=(other);
	width = other.width;
	height = other.height;
	leftUp = other.leftUp;
	return *this;
}
int Rectangle::getArea() const{
	return width * height;
}
Circle::Circle(int no, int radius, int x, int y): Shape(no), radius(radius), center(x, y){ }
Circle::Circle(const Circle& other): Shape(other.getNo()),radius(other.radius), center(other.center){ }
Circle& Circle::operator=(const Circle& other){
	if(this == &other){
		return *this;
	}
	this->Shape::operator=(other);
	radius = other.radius;
	center = other.center;
	return *this;
}
int Circle::getArea() const{
	return 3 * radius * radius; 
}
#endif

int main(){
	
	Shape* A[20];
	for(int i = 0; i < 20; ++i){
		if(i < 10)
			A[i] = new Rectangle(i+1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
		else
			A[i] = new Circle(i+1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
	}

	int j = 0;
	for(int i = 0; i < 20; ++i){
		if(A[i]->getArea() > 50){
			if(A[j] != A[i]){
				delete A[j];
				A[j] = A[i];
			}
			j++;
		}
	}
	for(int i = 0; i < j; i++){
		cout << "no: " << A[i]->getNo() << " , area is: " << A[i]->getArea() << endl;
	}
}