#ifndef __SHAPE_H__
#define __SHAPE_H__

namespace GeekBand {

struct Shape {
  Shape() : no_(0) {}
  int no_;
  virtual int getArea() = 0;
  virtual ~Shape() {}
};

struct Point {
  Point() : x_(0), y_(0) {}
  Point(int x, int y) : x_(x), y_(y) {}
  int x_;
  int y_;
};

} //  GeekBand

#endif
