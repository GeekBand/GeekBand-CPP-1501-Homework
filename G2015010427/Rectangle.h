#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <iostream>

namespace GeekBand {

static int num = 0;

/*
struct Shape;
struct Point;
class Rectangle;

std::ostream& operator<<(std::ostream& out, const Rectangle& rec) {
  out << "[Rec No." << rec.no_ << "]";
  out << "[width:" << rec.width_ << "]";
  out << "[height:" << rec.height_ << "]";
  out << "[Point:x->" << rec.leftUp_->x_ << ",y->" << rec.leftUp_->y_ << "]";
  return out;
}
*/

struct Shape {
  Shape() : no_(num++) {}
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
  Rectangle(int width, int height, int x, int y);
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
