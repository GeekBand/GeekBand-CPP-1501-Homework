//
// Created by Yzhh on 2015/8/14.
//

#ifndef G2015010558_SHAPE_H
#define G2015010558_SHAPE_H

#include <iostream>

class Shape
{
public:
    virtual int getArea() = 0;
    virtual void set_no(int n)
    {
        no = n;
    }
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
    // constructor
    Rectangle(int _width, int _height, int x, int y)
            : width(_width), height(_height), leftUp(new Point(x, y)) {}

    // copy constuctor
    Rectangle(const Rectangle& other)
    {
        std::cout << "copy constructor called" << std::endl;
        width = other.width;
        height = other.height;

        leftUp = new Point();
        *leftUp = *other.leftUp;
    }
    // assign operator
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

    //destructor
    ~Rectangle()
    {
        delete leftUp;
    }

public:

    virtual int getArea() override
    {
        return width * height;
    }

private:
    int width;
    int height;

    Point *leftUp;
};

class Circle : public Shape
{
public:
    // constructor
    Circle(int x, int y, int r) : center(new Point(x, y)), radius(r) {}
    // copy constructor
    Circle(const Circle& other)
    {
        this->radius = other.radius;
        center = new Point();
        *center = *other.center;
    }
    // assign operator
    Circle& operator=(const Circle& rhs)
    {
        if (this == &rhs)
            return *this;
        this->radius = rhs.radius;

        delete center;
        center = new Point();
        *center = *rhs.center;
    }
    // destructor
    ~Circle()
    {
        delete center;
    }

public:
    static constexpr double PI = 3.1415;

    virtual int getArea() override
    {
        return static_cast<int>(PI * radius * radius);
    }
private:
    Point *center;
    int radius;
};



#endif //G2015010558_SHAPE_H
