#include "Rectangle.h"
#include "Circle.h"
#include <random>
#include <ctime>

using namespace GeekBand;

Shape** getRandomArray(size_t *len) {
  std::default_random_engine random(time(nullptr));
  std::uniform_int_distribution<int> r(1, 10);
  Shape** arr = new Shape*[20];
  for (size_t i = 0; i < 20; ++i) {
    arr[i] = nullptr;
  }
  for (size_t i = 0; i < 10; ++i) {
    arr[i] = new Rectangle(i, r(random), r(random), r(random), r(random));
  }
  for (size_t i = 10; i < 20; ++i) {
    arr[i] = new Circle(i, r(random), r(random), r(random));
  }
  int num = 0;
  for (size_t i = 0; i < 20; ++i) {
    if (arr[i]->getArea() < 50) {
      delete arr[i];
      arr[i] = nullptr;
    } else {
      num++;
    }
  }
  Shape** output = new Shape*[num];
  for (size_t i = 0, j = 0; i < 20 && j < num; ++i) {
    if (nullptr != arr[i]) {
      output[j++] = arr[i];
    }
  } 
  for (size_t i = 0; i < 20; ++i) {
    if (nullptr != arr[i]) {
      arr[i] = nullptr;
    }
  }
  delete[] arr;
  *len = num;
  return output;
}

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

  std::cout << "============================" << std::endl;
  Circle cir1(1, 2, 4, 5);
  std::cout << "after init cir1 (1, 2, 4, 5)" << std::endl;
  std::cout << cir1;

  std::cout << "============================" << std::endl;

  size_t num;
  Shape** arr = getRandomArray(&num);
  for (size_t i = 0; i < num; ++i) {
    std::cout << "[" << i << "]" << arr[i]->getArea() << std::endl;
  }
  for (size_t i = 0; i < num; ++i) {
    if (nullptr != arr[i]) {
      delete arr[i];
    }
  }
  delete[] arr;
  return 0;
}
