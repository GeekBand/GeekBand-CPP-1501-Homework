//为下面的 Rectangle 类实现构造函数,拷贝构造函数,赋值操作符,析构函数。

#ifndef _RECTANGLE_
#define _RECTANGLE_
#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
private:
    int no;
public:
    Shape(int no=0):no(no){};
    virtual ~Shape(){};
    
};
class Point
{
private:
    int x;
    int y;
public:
    Point(int x,int y):x(x),y(y){};
};
class Rectangle: public Shape
{
    int width;
    int height;
    Point * leftUp;
public:
    Rectangle(int width=0, int height=0, int x=0, int y=0,int no=0);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle();
    int get_data(){cout<< width<<endl;
        cout << height<<endl;
        return 0;}
};

inline Rectangle::Rectangle(int width,int height,int x,int y,int no):width(width),height(height),leftUp(new Point(x,y)),Shape(no)
{};

inline Rectangle::Rectangle(const Rectangle& other):Shape(other),width(other.width),height(other.height)
{
    if (other.leftUp!=nullptr){
        this->leftUp=new Point(*other.leftUp);
    }
    else {
        this->leftUp=nullptr;
    }
    
}

inline Rectangle& Rectangle::operator = (const Rectangle& other)
{
    if (leftUp!=nullptr && other.leftUp!=nullptr)
    {
        *leftUp=*other.leftUp;
    }
    else
    {
        if(leftUp==nullptr && other.leftUp!=nullptr)
        {
            leftUp=new Point(*other.leftUp);
        }
        else if (other.leftUp==nullptr && leftUp!= nullptr)
        {
            delete leftUp;
            this->leftUp=nullptr;
        }
        else
        {
            
        }
    }
    this->Shape::operator=(other);//调用父类赋值操作符
    return *this;
}

inline Rectangle::~Rectangle()
{
    delete leftUp;
    leftUp=nullptr;
}


#endif