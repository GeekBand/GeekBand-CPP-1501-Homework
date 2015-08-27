#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Shape.h"
#include "Point.h"
#include <iostream>
#include <assert.h>

class Point;

class Rectangle: public Shape
{
private:
  const int width_;
  const int height_;
  const Point *leftUp_;
  friend std::ostream &operator<< (std::ostream &os, const Rectangle &rc);
public:
  Rectangle(int width, int height, int x, int y, int no);
  ~Rectangle() { delete leftUp_; }

public:
  int with() const { return width_; }
  int height() const { return height_; }
  const Point & leftup() const { return *leftUp_; }
  int getArea() const { return width_ * height_; }
  void print() const { std::cout << *this; }
 
private:
  // disable the copy ctor and copy assign ctor,
  // since every shape is an uniq object with different no.
  Rectangle(const Rectangle& other);
  Rectangle& operator=(const Rectangle& other);
};

inline
Rectangle::Rectangle(int width, int height, int x, int y, int no) : 
  Shape(no)
  , width_(width)
  , height_(height)
  , leftUp_(new Point(x, y))
{
  // ensure this retangle has a correct size
  assert(width_ > 0);
  assert(height_ > 0);
}

inline std::ostream &
operator<< (std::ostream &os, const Rectangle &rc) 
{
  return os << "{ RECT " << rc.no() << ": " 
    << "[" << rc.leftup().x() << ", " << rc.leftup().y()  << "] , " 
    << rc.with() << ", " << rc.height() << " }";
}

#endif