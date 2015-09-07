#include "Rectangle.h"

using namespace GeekBand;

int main() {
  Rectangle rec1(1, 1, 2, 3, 5);
  std::cout << "after init rec1 (1, 2, 3, 5)" << std::endl;
  std::cout << rec1;
  Rectangle rec2(rec1);
  std::cout << "after init rec2 with rec1" << std::endl;
  std::cout << rec2;
  Rectangle rec3(3, 3, 4, 5, 6);
  std::cout << "after init rec3 (3, 4, 5, 6)" << std::endl;
  std::cout << rec3;
  Rectangle rec4(4, 8, 9, 3, 1);
  std::cout << "after init rec4 (8, 9, 3, 1)" << std::endl;
  std::cout << rec4;
  rec3 = rec2;
  std::cout << "after rec3=rec2" << std::endl;
  std::cout << rec2;
  std::cout << rec3;
  rec4 = rec3 = rec2;
  std::cout << "rec4 = rec3 = rec2" << std::endl;
  std::cout << rec2;
  std::cout << rec3;
  std::cout << rec4;
  return 0;
}
