#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Shape.hpp"
#include <iostream>

namespace GeekBand {

class Circle : public Shape {
friend std::ostream& operator<<(std::ostream& out, const Circle& cir);
public:
  Circle(int no, int radius, int x, int y);
  Circle(const Circle& other);
  Circle& operator=(const Circle& other);
  virtual int getArea();
  virtual ~Circle();
private:
  int radius_;
  Point* center_;
};

} //  GeekBand

#endif
