#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <iostream>

namespace GeekBand {

struct Shape {
  Shape() : no_(0) {}
  int no_;
};

struct Point {
  Point() : x_(0), y_(0) {}
  Point(int x, int y) : x_(x), y_(y) {}
  int x_;
  int y_;
};

class Rectangle : public Shape {
friend std::ostream& operator<<(std::ostream& out, const Rectangle& rec);
public:
  Rectangle(int no, int width, int height, int x, int y);
  Rectangle(const Rectangle& other);
  Rectangle& operator=(const Rectangle& other);
  ~Rectangle();
private:
  int width_;
  int height_;
  Point* leftUp_;
};

} //  Geekband

#endif
