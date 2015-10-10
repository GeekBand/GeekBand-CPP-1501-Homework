// The abstract definition of shape stuff
#ifndef __SHAPE_H__
#define  __SHAPE_H__

class Shape {
private:
  const int no; // to simplify the id generator
private:
  static int count;
public:
  virtual ~Shape() { }

public:
  Shape() : no(++count) { }
  const int id() const { return no; }
};

#endif // __SHAPE_H__