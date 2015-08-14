#ifndef __RETANGLE_H__
#define __RETANGLE_H__

#include "Shape.h"
#include <iostream>
#include <assert.h>

class Rectangle: public Shape
{
private:
  int width_;
  int height_;
  Point *leftUp_;

public:
  Rectangle(int width, int height, int x, int y);
  Rectangle(const Rectangle& other);
  Rectangle& operator=(const Rectangle& other);
  ~Rectangle() { delete leftUp_; }

public:
  int with() const { return width_; }
  int height() const { return height_; }
  const Point & leftup() const { return *leftUp_; }
};

inline
Rectangle::Rectangle(int width, int height, int x, int y) : 
  width_(width)
  , height_(height)
  , leftUp_(new Point(x, y))
{
  // ensure this retangle has a correct size
  assert(width_ > 0);
  assert(height_ > 0);
}

inline
Rectangle::Rectangle(const Rectangle &other) : 
  width_(other.width_)
  , height_(other.height_)
  , leftUp_(new Point(other.leftUp_->x(), other.leftUp_->y()))
{
  // ensure this retangle has a correct size
  assert(width_ > 0);
  assert(height_ > 0);
}

inline Rectangle &
Rectangle::operator= (const Rectangle &other) 
{
  if (this == &other) {
    return *this;
  }

  delete leftUp_;
  width_ = other.width_;
  height_ = other.height_;
  leftUp_ = new Point(other.leftUp_->x(), other.leftUp_->y());
  return *this;
}

inline std::ostream &
operator<< (std::ostream &os, const Rectangle &rc) 
{
  return os << "{ " << rc.id() << ": " 
    << "[" << rc.leftup().x() << ", " << rc.leftup().y()  << "] , " 
    << rc.with() << ", " << rc.height() << "}";
}

#endif