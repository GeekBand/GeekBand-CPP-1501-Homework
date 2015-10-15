#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Shape.hpp"
#include <iostream>

namespace GeekBand {

class Rectangle : public Shape {
friend std::ostream& operator<<(std::ostream& out, const Rectangle& rec);
public:
  Rectangle(int no, int width, int height, int x, int y);
  Rectangle(const Rectangle& other);
  Rectangle& operator=(const Rectangle& other);
  virtual int getArea();
  virtual ~Rectangle();
private:
  int width_;
  int height_;
  Point* leftUp_;
};

} //  Geekband

#endif
