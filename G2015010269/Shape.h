#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <cstdio>

class Shape
{
 public:
  Shape(): no_(0) { }
  Shape(int no): no_(no) { }
  virtual ~Shape() { }

  virtual void printInfo() const 
  { printf("No of sharp is %d\n", no_); }

  virtual void draw() const = 0;

  int no() const { return no_; }
  void no(int noVal) { no_ = noVal; }
 private:
 protected:
  int no_;
};

#endif

