#include "Rectangle.h"

namespace GeekBand {

Rectangle::Rectangle(int width, int height, int x, int y) :
  width_(width), height_(height), leftUp_(new Point(x, y)) {}

Rectangle::Rectangle(const Rectangle& other) :
  width_(other.width_), height_(other.height_) {
  leftUp_ = new Point(other.leftUp_->x_, other.leftUp_->y_);
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
  if (this == &other) {
    return *this;
  }
  if (leftUp_ != nullptr) {
    delete leftUp_;
  }
  width_ = other.width_;
  height_ = other.height_;
  leftUp_ = new Point(other.leftUp_->x_, other.leftUp_->y_); 
  return *this;
}

Rectangle::~Rectangle() {
  delete leftUp_;
}

} //  GeekBand

