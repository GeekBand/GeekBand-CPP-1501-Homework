#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape
{
    int no;
};

class Point
{
    int x;
    int y;
public:
    Point( int _x = 0, int _y = 0 ) : x( _x ), y( _y ) {};
    
    int get_x() const { return x; }
    int get_y() const { return y; }
};

class Rectangle : public Shape
{
    int width;
    int height;

    Point *leftUp;

public:
    Rectangle( int width, int height, int x, int y);
    Rectangle( const Rectangle& other );
    Rectangle& operator=( const Rectangle& other );
    ~Rectangle();

    string str();
};

ostream& operator<<( ostream& os, const Rectangle& rec );

#endif
