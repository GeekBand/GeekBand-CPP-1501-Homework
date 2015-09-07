#include <cstdio>

#include "Rectangle.h"

void drawShape(const Shape *shape)
{
  shape->printInfo();
  shape->draw();
}

int main(int argc, char *argv[])
{
  Rectangle *rectangle0 = new Rectangle();
  delete rectangle0;

  Rectangle *rectangle1 = new Rectangle();
  drawShape(rectangle1);

  Rectangle *rectangle2 = new Rectangle(2, 5, 5, 0, 0);
  //rectangle2->no(1);
  drawShape(rectangle2);

  Rectangle *rectangle3 = new Rectangle(*rectangle2);
  drawShape(rectangle3);

  *rectangle1 = *rectangle2;
  drawShape(rectangle2);
  drawShape(rectangle1);

  rectangle1->x(1);
  rectangle1->y(1);
  rectangle1->width(6);
  rectangle1->height(6);
  rectangle1->no(1);

  drawShape(rectangle2);
  drawShape(rectangle1);

  *rectangle2 = *rectangle2;
  drawShape(rectangle2);

  Shape *recShape1 = rectangle1;
  Shape *recShape2 = rectangle2;

  delete recShape1;
  delete recShape2;
  delete rectangle3;

  return 0;
}

