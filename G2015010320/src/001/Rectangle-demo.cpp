#include "Rectangle.h"
#include <iostream>
#include <assert.h>

int Shape::count = -1;
int main() {
  Rectangle r1 = Rectangle(3, 4, 1, 2);
  Rectangle r2 = r1;
  Rectangle r3 = Rectangle(5, 6, 2, 3);
  r1 = r3;

  std::cout << r1 << std::endl
    << r2 << std::endl
    << r3 << std::endl;

 return 0;
}