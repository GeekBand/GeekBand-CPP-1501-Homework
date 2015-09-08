//
//  shape.h
//  1
//
//  Created by 何彬 on 15/9/3.
//  Copyright (c) 2015年 何彬. All rights reserved.
//

#ifndef __shape_h
#define __shape_h
class Shape
{
private:
    int no;
public:
    Shape(int _no = 0) : no(_no) {}
    virtual ~Shape() {}
    virtual int getArea() = 0;
    virtual void print() const = 0;
    int no_() const { return no; }
};

class Point {
private:
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    ~Point() {}
    int x_() const { return x; }
    int y_() const { return y; }
};

std::ostream& operator<< (std::ostream& os, const Point& point)
{
    os << "( " << point.x_() << " , " << point.y_() << " )";
    return os;
}

class Rectangle: public Shape
{
private:
    int width;
    int height;
    Point leftUp;
public:
    Rectangle( int _width = 0, int _height = 0, int _x = 0, int _y = 0, int _no = 0)
    : Shape(_no), width(_width), height(_height), leftUp(Point(_x, _y)) {}
    virtual int getArea() const {return this->height_() * this->width_(); }
    virtual void print() const {
        std::cout << "Rectangle " << Shape::no_() << " Width: " << this->width_()
        << " Height: " << this->height_() << " Leftup: " << this->get_leftUp()
        << " Area: " << this->getArea() << std::endl;
    }
    
    int width_() const { return this->width; }
    int height_() const { return this->height; }
    Point get_leftUp() const { return leftUp; }
};

class Circle: public Shape
{
private:
    Point center;
    int radius;
public:
    Circle(int _radius = 0, int _x = 0, int _y = 0, int _no = 0) : Shape(_no), center(Point(_x, _y)), radius(_radius) {}
    int radius_() const { return radius; }
    Point get_center() const { return center; }
    virtual int getArea() const { return 3 * this->radius_() * this->radius_(); }
    virtual void print() const {
        std::cout << "Circle " << Shape::no_() << " Radius: " << this->radius_()
        << " Center: " << this->get_center() << " Area: " << this->getArea() << std::endl;
    }
};


#endif
