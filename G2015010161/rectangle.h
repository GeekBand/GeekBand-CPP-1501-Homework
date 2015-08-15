#ifndef __RECTANGLE__
#define __RECTANGLE__
#include <iostream>
using std::ostream;

class Shape
{
private:
    int no;
};

class Point
{
public:
    Point(int a, int b):
        x(a), y(b) {}

    int getX() const {return x;}
    int getY() const {return y;}
private:
    int x;
    int y;
};

class Rectangle: public Shape
{
public:
    Rectangle(int, int, int, int);
    Rectangle(const Rectangle&);
    Rectangle &operator=(const Rectangle&);
    ~Rectangle();

    friend ostream &operator<<(ostream &, const Rectangle&);

private:
    int width;
    int height;

    Point *leftUp;
};

#endif
