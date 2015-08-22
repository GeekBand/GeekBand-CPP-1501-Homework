#include "rectangle.h"
#include "iostream"
Rectangle::Rectangle(int width, int height, int x, int y) : width(width),height(height)
{
    std::cout<<"Constructor"<<std::endl;
    leftUp = new Point(x,y);
}

Rectangle::Rectangle(const Rectangle &other):Shape(other),width(other.width),height(other.height)
{
    //
    std::cout<<"Copy Constructor"<<std::endl;

    if(other.leftUp != nullptr)
        leftUp = new Point(*other.leftUp);
    else
        leftUp = nullptr;
}
Rectangle& Rectangle::operator=(const Rectangle& other)
{
    std::cout<<"Copy Assignment"<<std::endl;

    if(this == &other)
        return *this;
    this->Shape::operator=(other);
    width = other.width;
    height = other.height;
    if(other.leftUp!=nullptr && leftUp != nullptr)
        *leftUp = *other.leftUp;
    else if(other.leftUp == nullptr)
    {
        if(leftUp != nullptr)
        {
            delete leftUp;
            leftUp = nullptr;
        }
    }
    else if(leftUp == nullptr)
    {
        if(other.leftUp != nullptr)
        {
            leftUp = new Point(*other.leftUp);
        }
    }
    return *this;
}

Rectangle::~Rectangle()
{
    if(leftUp!=nullptr) delete leftUp;
    std::cout<<"Destructor"<<std::endl;

}

