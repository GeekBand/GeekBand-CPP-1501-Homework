#ifndef GEEKBAND_HOMEWORK_SHAPE_H
#define GEEKBAND_HOMEWORK_SHAPE_H

class Shape {
 public:
  Shape(int no = 0) : no_(no) { }

  bool Equals(const Shape& other) const {
      if (this == &other) {
          return true;
      }
      return no_ == other.no_;
  }

 private:
  int no_;
};

#endif  // GEEKBAND_HOMEWORK_SHAPE_H

