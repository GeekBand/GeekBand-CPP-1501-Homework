#ifndef GEEKBAND_HOMEWORK_POINT_H
#define GEEKBAND_HOMEWORK_POINT_H

class Point {
 public:
  Point(int x, int y) : x_(x), y_(y) { }

  bool Equals(const Point& other) const {
      if (this == &other) {
          return true;
      }
      return x_ == other.x_ && y_ == other.y_;
  }

 private:
  int x_;
  int y_;
};

#endif  // GEEKBAND_HOMEWORK_POINT_H

