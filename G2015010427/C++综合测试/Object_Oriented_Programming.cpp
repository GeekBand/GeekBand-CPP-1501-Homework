//面向对象与设计 第一题

class Shape {
public:
  int no;
};

class Point {
public:
  int x;
  int y;
};

class Polygon : public Shape {
public:
  Polygon(const vector<Point>& initv, int no) : no(no) {
    if (initv.empty()) {
      points = nullptr;
    }
    len = initv.size();
    points = new Points[len]; 
    for (size_t i = 0; i < len; ++i) {
      points[i].x = initv[i].x;
      points[i].y = initv[i].y;
    }
  }
  ~Polygon() {
    if (points != nullptr) {
      delete[] points;
    }
  }
  Polygon(const Polygon& pyg) : len(pyg.len), no(pyg.no) {
    points = new Points[len];
    for (size_t i = 0; i < len; ++i) {
      points[i].x = pyg.points[i].x;
      points[i].y = pyg.points[i].y;
    }
  }
  Polygon& operator=(const Polygon& pyg) {
    if (this == &pyg) {
      return *this;
    }
    delete[] points;
    no = pyg.no;
    len = pyg.len;
    points = new Points[len];
    for (size_t i = 0; i < len; ++i) {
      points[i].x = pyg.points[i].x;
      points[i].y = pyg.points[i].y;
    }   
    return *this;
  }
private:
  Point* points;
  size_t len;
};


//面向对象与设计 第二题
