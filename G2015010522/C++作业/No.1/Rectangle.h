/*
 * Rectangle.h
 *
 *  Created on: 2015年8月9日
 *      Author: Administrator
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "Shape.h"
#include "Point.h"

class Rectangle:public Shape {
private:
	int width;
	int height;
	Point * leftUp;
public:
	Rectangle(int width, int height, int x, int y);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	~Rectangle();
};

#include <iostream>
inline
Rectangle::Rectangle(int width, int height, int x, int y)
:Shape(),width(width),height(height){
	leftUp = new Point(x,y);
	//std::cout << "Rectangle -- width, height, x, y,  no :"
	//<< width <<" "<< height <<" "<<leftUp->getX() <<" "<<leftUp->getY()<<" "<< this->getNo()<<std::endl;
}

inline
Rectangle::Rectangle(const Rectangle& other):Shape(){
	this->width = other.width;
	this->height = other.height;
	this->leftUp = new Point(other.leftUp->getX(),other.leftUp->getY());
	/*std::cout << "Rectangle source-- width, height, x, y,  no :"
	<<other.width<<" "<<other.height<<" "<<other.leftUp->getX()<<" "<<other.leftUp->getY()<<" "<< other.getNo()<<std::endl;
	std::cout << "Rectangle copy-- width, height, x, y,  no :"
	<<this->width<<" "<<this->height<<" "<<this->leftUp->getX()<<" "<<this->leftUp->getY()<<" "<< this->getNo()<<std::endl;

*/}

inline
Rectangle& Rectangle::operator=(const Rectangle& other){
	if (this == &other){
		//std::cout << "this== &other" <<std::endl;
	      return *this;}
	this->width = other.width;
	this->height = other.height;
	delete this->leftUp;
	this->leftUp = new Point(other.leftUp->getX(),other.leftUp->getY());
	/*std::cout << "Rectangle operator= right-- width, height, x, y,  no :"
			<<other.width<<" "<<other.height<<" "<<other.leftUp->getX()<<" "<<other.leftUp->getY()<<" "<< other.getNo()<<std::endl;
	std::cout << "Rectangle operator = left-- width, height, x, y,  no :"
				<<this->width<<" "<<this->height<<" "<<this->leftUp->getX()<<" "<<this->leftUp->getY()<<" "<< this->getNo()<<std::endl;*/

	return *this;
}

inline
Rectangle::~Rectangle(){
	delete this->leftUp;
}


#endif /* RECTANGLE_H_ */
