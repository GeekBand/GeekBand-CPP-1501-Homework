#ifndef _POINT_H_
#define _POINT_H_

class Point
{
 public:
  Point(): x_(0), y_(0) { }
  Point(int x, int y)
      : x_(x), y_(y) { }
  Point(const Point& other)
      : x_(other.x_),
        y_(other.y_) { }
  
  int x() const { return x_; }
  int y() const { return y_; }
  void x(int xVal) { x_ = xVal; }
  void y(int yVal) { y_ = yVal; }
 private:
  int x_;
  int y_;
};

#endif

