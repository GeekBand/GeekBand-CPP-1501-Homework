#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#define RECTANGLE 1


class Shape
{
protected:
    int no;
};

class Rectangle;
class Point
{
public:
    
    Point(int _x, int _y):x(_x), y(_y){}
    Point(const Point& other);
    Point& operator=(const Point& other);
    
    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_count() const { return count; }
    //因为矩形里面使用delegation的形式,所以这里面要加入引用计数,以节省空间
    //具体体现在，Rectangle的拷贝构造函数和赋值构造函数里面count++
    //析构的时候要检查引用计数
    int count;

private:
    friend class Rectangle;
    int x;
    int y;

};

class Rectangle: public Shape
{

public:
    Rectangle(int _width, int _height, int _x, int _y);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    
    ~Rectangle();
    
    int get_width() const { return width; }
    int get_height() const { return height; }
    Point& get_point() const { return *leftUp; }
    
private:
    int width;
    int height;

    Point* leftUp;
    //添加一些辅助属性
    //中心点
    Point* center;
    //面积
    double square;
    //周长
    double circumstance;
};

inline
Point::Point(const Point& other)
{
    x = other.x;
    y = other.y;
    count = 0;
}

inline Point&
Point::operator=(const Point& other)
{
    if(this == &other)
    {
        return *this;
    }
    this->x = other.x;
    this->y = other.y;
    count = 0;
    return *this;
}

inline
Rectangle::Rectangle(int _width, int _height, int _x, int _y)
{
    //x, y为左上坐标，width为宽度，height为高度
    leftUp = new Point(_x, _y);
    width = _width;
    height = _height;
}

inline
Rectangle::Rectangle(const Rectangle& other)
{
    leftUp = other.leftUp;
    other.leftUp->count++;
    width = other.width;
    height = other.height;
}

inline Rectangle&
Rectangle::operator=(const Rectangle& other)
{
    if(this == &other)
    {
        return *this;
    }
    delete leftUp;
    leftUp = other.leftUp;
    other.leftUp->count++;
    width = other.width;
    height = other.height;
    return *this;
}

#include<iostream>
using namespace std;


inline ostream&
operator<<(ostream& os, const Rectangle& r)
{
    return os << '(' << r.get_point().get_x() << ','
                  << r.get_point().get_y() << ','
                  << r.get_width() << ','
                  << r.get_height() << ')'
                  << "count:" << r.get_point().get_count(); 
}

inline
Rectangle::~Rectangle()
{
    if(leftUp->count > 0)
    {
        leftUp->count--;
    }
    else
    {
        delete leftUp;
    }

}

#endif
