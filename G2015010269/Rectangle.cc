#include <algorithm>

#include "Rectangle.h"

Rectangle& Rectangle::operator=(const Rectangle& other)
{
  if (this == &other)
  {
    return *this;  
  }

  Shape::operator=(other);

  width_ = other.width_;
  height_ = other.height_;

  Point *pOld = leftUp_;
  leftUp_ = new Point(*other.leftUp_);
  delete pOld;

  return *this;
}

Rectangle::~Rectangle()
{
  if (leftUp_ != 0)
  {
    delete leftUp_; 
  }
  
  //用于测试
  printf("~Rectangle\n");
}

void Rectangle::printInfo() const
{
  printf("It is a rectangle, no is %d\n", no_);
}

void Rectangle::draw() const
{
  if (leftUp_ != 0)
  {
    printf("Draw a rectangle, x = %d, y = %d, "
          "width = %d, height = %d\n",
          leftUp_->x(), leftUp_->y(),
          width_, height_);
  }
  else
  {
    printf("Invalid rectangle!\n"); 
  }
}

