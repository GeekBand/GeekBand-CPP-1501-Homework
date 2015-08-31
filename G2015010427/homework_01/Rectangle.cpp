#include "Rectangle.h"

namespace GeekBand {

Rectangle::Rectangle(int no, int width, int height, int x, int y) :
  width_(width), height_(height), leftUp_(new Point(x, y)) {
  no_ = no;
}

Rectangle::Rectangle(const Rectangle& other) :
  width_(other.width_), height_(other.height_) {
  no_ = other.no_;
  leftUp_ = new Point(other.leftUp_->x_, other.leftUp_->y_);
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
  if (this == &other) {
    return *this;
  }
  if (leftUp_ != nullptr) {
    delete leftUp_;
  }
  no_ = other.no_;
  width_ = other.width_;
  height_ = other.height_;
  leftUp_ = new Point(other.leftUp_->x_, other.leftUp_->y_); 
  return *this;
}

Rectangle::~Rectangle() {
  delete leftUp_;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& rec) {
  out << "[Rec No." << rec.no_ << "]";
  out << "[width:" << rec.width_ << "]";
  out << "[height:" << rec.height_ << "]";
  out << "[Point:x->" << rec.leftUp_->x_ << ",y->" << rec.leftUp_->y_ << "]\n";
  return out;
}

} //  GeekBand

