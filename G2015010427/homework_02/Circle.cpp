#include "Circle.h"

namespace GeekBand {

Circle::Circle(int no, int radius, int x, int y) :
  radius_(radius), center_(new Point(x, y)) {
  no_ = no;
}

Circle::Circle(const Circle& other) :
  radius_(other.radius_), center_(new Point(other.center_->x_, other.center_->y_)) {
  no_ = other.no_;
}

Circle& Circle::operator=(const Circle& other) {
  if (this == &other) {
    return *this;
  }
  if (nullptr != this->center_) {
    delete center_;
  }
  no_ = other.no_;
  radius_ = other.radius_;
  center_ = new Point(other.center_->x_, other.center_->y_);
  return *this;
}

int Circle::getArea() {
  return 3 * radius_ * radius_;
}

Circle::~Circle() {
  delete center_;
}

std::ostream& operator<<(std::ostream& out, const Circle& cir) {
  out << "[Cir No." << cir.no_ << "]";
  out << "[radius:" << cir.radius_ << "]";
  out << "[Center:x->" << cir.center_->x_ << ",y->" << cir.center_->y_ << "]\n";
  return out;
}

} //  GeekBand
