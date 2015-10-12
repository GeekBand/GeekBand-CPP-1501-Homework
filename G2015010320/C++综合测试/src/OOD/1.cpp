// The entry point of Question 1

#include "Point.h"
#include "Polygon.h"

// define and init the id genarator
int Shape::count = -1;
int main()
{
  std::vector<const Point *> points;
  for (int i = 0; i < 3; ++i) {
    for (int j = 2; j >= 0; --j) {
      points.push_back(new Point(i, j));
    }
  }

  Polygon pg1(points);
  std::cout << pg1 << std::endl;
  Polygon pg2(pg1);
  // update the 2nd point of pg2
  pg2.at(1) = Point(100, 100); 
  std::cout << pg2 << std::endl;

  return 0;
}