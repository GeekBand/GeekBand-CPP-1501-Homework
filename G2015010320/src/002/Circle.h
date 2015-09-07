#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Shape.h"
#include "Point.h"
#include <iostream>
#include <assert.h>

class Point;

class Circle: public Shape
{
private:
  const int radius_;
  const Point *center_;
  friend std::ostream &operator<< (std::ostream &os, const Circle &rc);
public:
  Circle(int radius, int x, int y, int no);
  ~Circle() { delete center_; }

public:
  int radius() const { return radius_; }
  const Point & center() const { return *center_; }
  int getArea() const { return 3.14 * radius_ * radius_; } // pei=3.14
  void print() const { std::cout << *this; }
  
private: 
  // disable the copy ctor and copy assign ctor,
  // since every shape is an uniq object with different no.
  Circle(const Circle& other);
  Circle& operator=(const Circle& other);
};

inline
Circle::Circle(int radius, int x, int y, int no) : 
  Shape(no)
  , radius_(radius)
  , center_(new Point(x, y))
{
  // ensure this circle has a correct size
  assert(radius_ > 0);
}

inline std::ostream &
operator<< (std::ostream &os, const Circle &c) 
{
  return os << "{ CIRC " << c.no() << ": " 
    << "[" << c.center().x() << ", " << c.center().y()  << "] , " 
    << c.radius() << " }";
}

#endif