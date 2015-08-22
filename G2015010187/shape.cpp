#include <iostream>
#include <sstream>
#include "shape.h"

inline
Rectangle::Rectangle( int width, int height, int x, int y)
{
    leftUp = new Point( x, y );

    this->width = width;
    this->height = height;
}

inline
Rectangle::Rectangle( const Rectangle& other )
{
    leftUp = new Point();
    *leftUp = *other.leftUp;

    width = other.width;
    height = other.height;
}

inline
Rectangle& Rectangle::operator=( const Rectangle& other )
{
    if ( this == &other )
        return *this;

    delete leftUp;
    leftUp = new Point();
    *leftUp = *other.leftUp;

    width = other.width;
    height = other.height;

    return *this;
}

inline
Rectangle::~Rectangle()
{
    delete leftUp;
}

inline
string Rectangle::str()
{
    ostringstream oss;
    oss << "Rectangle( x:" << leftUp->get_x() << " y:" << leftUp->get_y() << " width:" << width << " height:" << height << " )\n";
    return oss.str();
}

ostream& operator<<( ostream& os, Rectangle& rec )
{
    return os << rec.str();
}

/* Test code
int main()
{
    Rectangle r1( 10, 10, 1, 2 );
    Rectangle r2( r1 );
    Rectangle r3 = r2;
    cout << r1 << r2 << r3;
}
*/
