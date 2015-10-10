// definition of simple polygon
#ifndef __POLYGON_H__
#define __POLYGON_H__

#include "Shape.h"
#include <vector>
#include <iostream>
#include <cassert>

// note: it hands over the life of points
class Polygon : public Shape
{
private:
  std::vector<const Point *> ps_;

public:
  Polygon(const std::vector<const Point *> &ps) : ps_(ps) { }
  Polygon(const Polygon &p) : ps_(__deep_copy(p.points())) { }
  Polygon & operator=(const Polygon &p) {
    if (this == &p) {
      return *this;
    }

    __clean(ps_);
    ps_ = __deep_copy(p.points());
    return *this;
  }

  virtual ~Polygon() {
    __clean(ps_);
  }

public:
  const std::vector<const Point *> points() const {
    return ps_;
  }

  // the only data update interface for changing the 
  // Point at specified position
  // usage: Polygon.at(i) = Point(x,y);
  Point & at(int idx) const {
    assert(idx > 0 && idx < ps_.size());
    return const_cast<Point &>(*ps_.at(idx));
  }

private: // some helper methods
  void __clean(std::vector<const Point *> &ps) {
    for (int i = 0; i < ps.size(); ++i) {
      const Point *p = ps.at(i);
      delete p;
    }
    ps.clear();
  }

  std::vector<const Point *> __deep_copy(const std::vector<const Point *> &ps) {
    std::vector<const Point *> copy;
    for (int i = 0; i < ps.size(); ++i) {
      const Point *p = ps.at(i);
      copy.push_back(new Point(*p));
    }
    return copy;
  }
};

inline std::ostream &
operator<< (std::ostream &os, const Polygon &pg) {
  os << "[Polygon " << pg.id() << " : ";
  char dm[3] = { '\0', ' ', '\0' };
  for (int i = 0; i < pg.points().size(); ++i) {
    const Point *p = pg.points().at(i);
    os << dm << *p;
    dm[0] = ',';
  }
  os << " ]";
  return os;
}

#endif // __POLYGON_H__