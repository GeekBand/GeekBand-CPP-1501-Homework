#ifndef SHAPE_H
#define SHAPE_H

#include <ctime>
#include <cstdlib>

#include <iostream>
using namespace std;

const float PI = 3.14;

class Shape
{
public:
    Shape(int _no = 0)
        : no(_no) { }
    virtual ~Shape(){ }

    virtual int getArea() = 0;
    virtual void print() = 0;
    int getNo() const { return no;}

private:
    int no;
};

class Point
{
public:
    Point(int _x = 0, int _y = 0)
        : x(_x), y(_y) { }
    ~Point() { }
    Point(const Point& other) {
        x = other.x;
        y = other.y;
    }

    int getX() const { return x;}
    int getY() const { return y;}

    friend ostream& operator<< (ostream& os, const Point& point);

private:
    int x;
    int y;
};

class Rectangle : public Shape
{
public:
    Rectangle(int _no = 0, int _width = 0, int _height = 0, int _x = 0, int _y = 0)
        : Shape(_no), width(_width), height(_height), leftUp(Point(_x, _y)) { }
    Rectangle(int _no, int _width, int _height, Point& _point)
        : Shape(_no), width(_width), height(_height), leftUp(_point) { }
     ~Rectangle() { }

    int getArea() { return (width * height);}
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getX() const { return leftUp.getX(); }
    int getY() const { return leftUp.getY(); }

    void print();

private:
    int width;
    int height;
    Point leftUp;
};

class Circle : public Shape
{
public:
    Circle(int _no = 0, int _radius = 0, int _x = 0, int _y = 0)
        : Shape(_no), radius(_radius), center(Point(_x, _y)) { }
    Circle(int _no, int _radius, Point& _point)
        : Shape(_no), radius(_radius), center(_point) { }
    ~Circle() { }

    int getArea() { return (PI * radius * radius); }
    int getRadius() const { return radius;}
    int getX() const { return center.getX(); }
    int getY() const { return center.getY(); }

    void print();

private:
    int radius;
    Point center;
};



class ShapeFactory
{
public:
    ShapeFactory() { }
    ~ShapeFactory() { }
    virtual Shape* createShape(int no) = 0;
};

class RectangleFactory : public ShapeFactory
{
public:
    RectangleFactory() { }
    ~RectangleFactory() { }
    Shape* createShape(int no);
    static RectangleFactory* getRectangleFactory(){
        if(instance == NULL)
            instance = new RectangleFactory;
        return instance;
    }

private:
    static RectangleFactory*  instance;
};

class CircleFactory : public ShapeFactory
{
public:
    CircleFactory() { }
    ~CircleFactory() { }
    Shape* createShape(int no);
    static CircleFactory* getCircleFactory(){
        if(instance == NULL)
            instance = new CircleFactory;
        return instance;
    }

private:
    static CircleFactory* instance;
};

Shape* updateShapes(Shape** shapes, int size);



#endif // SHAPE_H
