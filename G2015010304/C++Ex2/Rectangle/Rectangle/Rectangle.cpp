#include "Rectangle.h"

Rectangle::Rectangle(int width, int height, int x, int y) : width(width), height(height), leftUp(Point(x, y))
{

}

Rectangle::Rectangle(int width, int height, Point leftUp) : width(width), height(height), leftUp(leftUp)
{

}
Rectangle::~Rectangle()
{
}

Point::Point(int x, int y) : x(x), y(y)
{
}

Circle::Circle(int x, int y, int radius) : radius(radius), center(Point(x, y))
{
}

Circle::~Circle()
{
}
