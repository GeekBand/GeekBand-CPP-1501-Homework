#ifndef __SHAPE_H__
#define __SHAPE_H__

class Shape {
private: 
  const int no_;
public:
  virtual ~Shape() { }
  
public:
  Shape(int no) : no_(no) { }
  int no() const { return no_; }
  virtual int getArea() const = 0;
  virtual void print() const = 0;
};

#endif