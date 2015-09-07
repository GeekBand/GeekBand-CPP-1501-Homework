#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Shape.h"
#include "Point.h"

class Rectangle: public Shape
{
 public:
  Rectangle(): width_(0), height_(0), leftUp_(0) { }
  Rectangle(int no, int width, int height, int x, int y)
      : Shape(no), width_(width), height_(height),
        leftUp_(new Point(x, y)) { }
  Rectangle(const Rectangle& other)
      : Shape(other),
        width_(other.width_),
        height_(other.height_),
        leftUp_(new Point(*(other.leftUp_))) { }
  Rectangle& operator=(const Rectangle& other);
  ~Rectangle();

  int width() const { return width_; }
  int height() const { return height_; }
  void width(int w) { width_ = w; }
  void height(int h) { height_ = h; }

  int x() const { return leftUp_->x(); }
  int y() const { return leftUp_->y(); }
  void x(int x) { leftUp_->x(x); }
  void y(int y) { leftUp_->y(y); }

  //覆写两个虚函数
  void printInfo() const;
  void draw() const; 
 private:
  int width_;
  int height_; 

  Point *leftUp_;
};

#endif

