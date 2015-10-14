// Definition of a point in graphic
#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>

class Point {
private:
  int x_;
  int y_;

public:
  explicit Point(int x, int y) 
    : x_(x), y_(y) { }
    
  Point & operator= (const Point &lhs) {
    if (this == &lhs) {
      return *this;
    }

    this->x_ = lhs.x_;
    this->y_ = lhs.y_;
    return *this;
  }

  int x() const { return x_; }
  int y() const { return y_; }
};

// overload operator << function for Point
inline std::ostream &
operator<< (std::ostream &os, const Point &p) {
  return os << "(P: " << p.x() << ", " << p.y() << ")";
}

inline bool
operator== (const Point &rhs, const Point &lhs) {
  return (rhs.x() == lhs.x() && rhs.y() == lhs.y());
}

inline bool
operator!= (const Point &rhs, const Point &lhs) {
  return !(rhs == lhs);
}

#endif // __POINT_H__