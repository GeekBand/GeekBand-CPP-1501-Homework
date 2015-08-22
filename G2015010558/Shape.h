//
// Created by Yzhh on 2015/8/14.
//

#ifndef G2015010558_SHAPE_H
#define G2015010558_SHAPE_H

#include <iostream>

class Shape
{
private:
    int no;
};

class Point
{
public:
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
private:
    int x;
    int y;
};

class Rectangle: public Shape
{
public:
    Rectangle(int _width, int _height, int x, int y)
            : width(_width), height(_height), leftUp(new Point(x, y)) {}
    Rectangle(const Rectangle& other)
    {
        std::cout << "copy constructor called" << std::endl;
        width = other.width;
        height = other.width;

        leftUp = new Point();
        *leftUp = *other.leftUp;
    }
    Rectangle& operator=(const Rectangle& other)
    {
        std::cout << "assign constructor called" << std::endl;
        if (this == &other)
            return *this;

        delete leftUp;
        leftUp = new Point();
        *leftUp = *other.leftUp;
        return *this;
    }
    ~Rectangle()
    {
        delete leftUp;
    }


private:
    int width;
    int height;

    Point *leftUp;
};



#endif //G2015010558_SHAPE_H
