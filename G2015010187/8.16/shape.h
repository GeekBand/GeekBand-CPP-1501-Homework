#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Shape
{
    int no;
protected :
    ostringstream info;
public :
    Shape();
    virtual ~Shape();

    void set_no( int n ) { no = n; }
    virtual string get_info() = 0;
    virtual int get_aero() = 0;
};

class Point
{
    int x;
    int y;
public :
    Point( int _x = 0, int _y = 0 ) : x( _x), y( _y) {}
    int get_x() const { return x; }
    int get_y() const { return y; }
};

class Rectangle : public Shape
{
    int width;
    int height;

    Point left_up;

public :
    Rectangle();
    Rectangle( int width, int height, int x, int y );
    Rectangle( int width, int height, const Point& left_up);
    ~Rectangle();

    virtual string get_info();
    virtual int get_aero();
};

ostream& operator<<( ostream& os, Rectangle& rec );

class Circle : public Shape 
{
    int r;

    Point center;

public :
    Circle();
    Circle( int r, int x, int y );
    Circle( int r, const Point& center );
    ~Circle();

    virtual string get_info();
    virtual int get_aero();
};

ostream& operator<<( ostream& os, Circle& c );

#endif
