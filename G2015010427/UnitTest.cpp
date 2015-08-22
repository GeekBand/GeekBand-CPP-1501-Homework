#include "Rectangle.h"

using namespace GeekBand;

int main() {
  Rectangle rec1(1, 2, 3, 5);
//  std::cout << rec1;
  Rectangle rec2(rec1);
  Rectangle rec3(3, 4, 5, 6);
  Rectangle rec4(8, 9, 3, 1);
  rec3 = rec2;
  rec4 = rec3 = rec2;
  return 0;
}
