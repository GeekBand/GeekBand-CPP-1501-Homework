#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_ value
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std ;

class Shape
{
public:
	Shape( int _no = 0  ) : no ( _no ) {
		this->no = ++ No ;
		std::cout << " Shape " << this->no << " ctor " << std::endl ;
	} 
	virtual ~Shape() {
		std::cout << " Shape " << this->no << " dtor " << std::endl ;
	}
	void setNo( int _no ) {
		this->no = _no ;
	}
	const int getNo( void ) const {
		return this->no ;
	}
protected:
	int no ; 
	static int No ;
};
class Point
{
public:
	Point( int _x = 0  , int _y = 0 ) : x( _x ) , y( _y ) {
		this->ob_No = ++ No  ;
		std::cout << " Point " << this->ob_No << " ctor " << std::endl ;
	}
	Point( const Point& other ) {
		this->ob_No = ++ No  ;
		std::cout << " Point " << this->ob_No << " ctor " << std::endl ;
	}
	Point& operator=( const Point& other ) {
		if( this == &other )
			return *this ;
		this->x = other.x ;
		this->y = other.y ;
	}
	virtual ~Point() {
		std::cout << " Point " << this->ob_No << " dtor " << std::endl ;
	}

	const int getX( void ) const {
		return this->x ;
	}
	const int getY( void ) const {
		return this->y ;
	}
	void setX( int _x ) {
		this->x = _x ;
	}
	void setY( int _y ) {
		this->y = _y ;
	}
	void setXY( int _x , int _y ) {
		this->x = _x ;
		this->y = _y ;
	}
	void info() const {
		std::cout << " Point (" << x << "," << y <<")" << std::endl ;
	}
	friend ostream& operator<<( ostream& os , const Point& it ) ;
protected:
	int x ; 
	int y ; 
	static int No ; 
	int ob_No ;
};

class Rectangle : public Shape 
{
public:
	Rectangle( int _x = 0 , int _y = 0 , int _weight = 0 , int _height = 0 , int _Shape = 0 ) : weight( _weight ) , height( _height ) ,  Shape( _Shape ){
		// std::cout << " Rectangle ctor " << std::endl ;
		this->leftup = new Point( _x , _y ) ;
	}
	Rectangle( const Point& _other , int _weight = 0 , int _height = 0 ) : weight( _weight ) , height( _height ) {
		this->leftup = new Point( _other.getX() , _other.getY() ) ;
	}
	Rectangle(  Point* _pother , int _weight = 0 , int _height = 0) : weight( _weight ) , height( _height ) {
		this->leftup = _pother ; 
	}
	Rectangle(const Rectangle& other ) {
		this->leftup = new Point( other.leftup->getX() , other.leftup->getY() ) ;
		this->weight = other.weight ;
		this->height = other.height ;
	}
	Rectangle( Rectangle* other ) {
		this->leftup = new Point( other->leftup->getX() , other->leftup->getY() ) ;
		this->weight = other->weight ;
		this->height = other->height ;
	}
	Rectangle& operator=( const Rectangle& other ) {
		if( this == &other ) 
    		return *this ; 
    	this->leftup->setXY( other.leftup->getX() , other.leftup->getY() ) ;
    	this->weight = other.weight ;
    	this->height = other.height ;
    	return *this ;
	}
	virtual ~Rectangle() {
		// std::cout << " Rectangle "<< this->ob_No << " dtor " << std::endl ;
		if( this->leftup == nullptr ) return ;
		delete this->leftup ;
		this->leftup = nullptr ;
	}
	const int getPerimeter() const {
		return 2 * ( this->weight + this->height ) ;
	}
	const int getArea() const {
		return this->weight * this->height ;
	}
	void info( void ) {
		std::cout << " Rectangle 属性：" ;
		std::cout << " Point (" << leftup->getX() << "," << leftup->getY() << ")" ;
		std::cout << " weight = " << this->weight  ;
		std::cout << " height = " << this->height  ;
		std::cout << " 编号：" << this->getNo() << std::endl ;
	}
	void setX( int _x ) {
		this->leftup->setX( _x ) ;
	}
	void setY( int _y ) {
		this->leftup->setY( _y ) ;
	}
	void setXY( int _x , int _y ) {
		this->leftup->setX( _x ) ;
		this->leftup->setY( _y ) ;
	}
	void setXY( const Point& _point ) {
		if( this->leftup == &_point ) return ;
		this->leftup->setXY( _point.getX() , _point.getY() ) ;
	}
	void setXY( Point* _point ) {
		if( this->leftup == _point ) return ;
		delete this->leftup ;
		this->leftup = _point ;
	}
	void setHeight( int _height ) {
		this->height = _height ;
	}
	void setWeight( int _weight ) {
		this->weight = _weight ;
	}
	const getHeight() const {
		return this->height ;
	}
	const getWeight() const {
		return this->weight ;
	}
	friend ostream& operator<<( ostream& os , const Rectangle& it ) ;
protected:
	int weight ;
	int height ;
	Point *leftup ;
};
int Shape::No  = 0 ;
int Point::No = 0 ;

inline ostream& operator<<( ostream& os , const Point& it ) {
	return os << " Point(" << it.getX() << "," << it.getY() << ")" ;
}
inline ostream& operator<<( ostream& os , const Rectangle& it ) {
	return os << " Rectangle 属性：" << *(it.leftup) << " weight = " << it.getWeight() << " height = " << it.getHeight() << " 编号：" << it.getNo() ;
}
#endif