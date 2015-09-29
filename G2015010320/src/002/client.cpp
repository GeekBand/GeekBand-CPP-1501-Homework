#include "Rectangle.h"
#include "Circle.h"
#include "Point.h"

#include <iostream>
#include <assert.h>

void initShapes(Shape **shapes, int size)
{
  const int SIZE = size;
  for (int i = 0; i < SIZE; ++i) {
    if (i % 2 == 0) {
      shapes[i] = new Rectangle(
        (rand() % 10) + 1 // width must be gt than 1
        , (rand() % 10) + 1 // height must be gt than 1
        , (rand() % 10)
        , (rand() % 10)
        , i+1);
    } else {
      shapes[i] = new Circle(
        (rand() % 10) + 1 // radius must be gt than 1
        , (rand() % 10)
        , (rand() % 10)
        , i+1);
    }
  }
}

// delete the shape which area is less than specific value,
// and shift all the elements after the item deleted to their left positions.
Shape **deleteLessThanArea(Shape **shapes, int size, int area)
{
  if (shapes == NULL || size <= 0) return shapes;

  int offset = 0;
  for (int i = 0; i < size; ++i) {
    if (shapes[i] != NULL 
      && shapes[i]->getArea() < area) {
      delete shapes[i];
      shapes[i] = NULL;
      ++offset;
    } else {
      if (offset > 0) {
        shapes[i - offset] = shapes[i];
        shapes[i] = NULL;
      }
    }
  }
  return shapes;
}

void print(Shape **shapes, int size)
{
  std::cout << "[" << std::endl;
    for (int i = 0; i < size; ++i) {
    if (shapes[i] != NULL) {
      shapes[i]->print();
      std::cout << std::endl;
    } else {
      std::cout << "NULL" << std::endl;
    }
  }
  std::cout << "]" << std::endl;
}

void clean(Shape **shapes, int size)
{
  for (int i = 0; i < size; ++i) {
    if (shapes[i] != NULL) {
      delete shapes[i];
    }
  }
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
  const int SIZE = 20;
  // It's not a good practice.
  // The raw point should be treated with RAII method,
  // so std::list<std::scoped_ptr<Shape>> is preferred.
  Shape *shapes[SIZE] = { NULL };
  srand((unsigned)time(0));
  initShapes(shapes, SIZE);

  std::cout << "Sample data: \n"
    << "---------------------" << std::endl;
  print(shapes, SIZE);

  deleteLessThanArea(shapes, SIZE, 50);
  std::cout << "\nAfter delete area value less than 50\n"
    << "---------------------" << std::endl;
  print(shapes, SIZE);

  std::cout << "clean all elements and exit" 
    << std::endl;
  clean(shapes, SIZE);

  return 0;
}