#ifndef __POINT_H__
#define __POINT_H__

class Point {
private:
  const int x_;
  const int y_;

public:
  Point(int x, int y) 
    : x_(x), y_(y) { }

  int x() const { return x_; }
  int y() const { return y_; }
};

#endif