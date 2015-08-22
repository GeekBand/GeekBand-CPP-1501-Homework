#ifndef __SHAPE_H__
#define __SHAPE_H__

class Shape {
private:
  const int no;
private:
  static int count;
public:
  virtual ~Shape() { }

public:
  Shape() : no(++count) { }
  const int id() const { return no; }
};

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