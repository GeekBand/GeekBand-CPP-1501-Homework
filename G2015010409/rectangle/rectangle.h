#ifndef GEEKBAND_HOMEWORK_RECTANGLE_H
#define GEEKBAND_HOMEWORK_RECTANGLE_H

#include <cassert>

#include "shape.h"
#include "point.h"

class Rectangle : public Shape {
friend std::ostream& operator<<(std::ostream& os, const Rectangle& r);
 public:
  Rectangle(int width, int height, int x, int y)
      : width_(width), height_(height) {
    left_up_ = new Point(x, y);
  }

  Rectangle(const Rectangle& other) : Shape(other), width_(other.width_), height_(other.height_) {
      assert(other.left_up_);
      left_up_ = new Point(*other.left_up_);
  }

  Rectangle& operator=(const Rectangle& other) {
      if (this == &other) {
          return *this;
      }
      Shape::operator=(other);
      width_ = other.width_;
      height_ = other.height_;
      assert(left_up_);
      assert(other.left_up_);
      *left_up_ = *other.left_up_;
      return *this;
  }

  bool Equals(const Rectangle& other) const {
      if (this == &other) {
          return true;
      }
      if (!Shape::Equals(other)) {
          return false;
      }
      if (width_ != other.width_ || height_ != other.height_) {
          return false;
      }
      assert(left_up_);
      assert(other.left_up_);
      return (*left_up_).Equals(*other.left_up_);
  }

  ~Rectangle() {
      delete left_up_;
      left_up_ = nullptr;
  }

 private:
  int width_;
  int height_;
  Point* left_up_;  // Owned.
};

#endif  // GEEKBAND_HOMEWORK_RECTANGLE_H

