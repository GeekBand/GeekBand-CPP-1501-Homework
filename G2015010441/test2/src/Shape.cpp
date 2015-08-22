#include "Shape.h"

CircleFactory* CircleFactory::instance = NULL;
RectangleFactory* RectangleFactory::instance = NULL;

ostream& operator<< (ostream& os, const Point& point)
{
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

void Rectangle::print()
{
    cout << "Rectangle " << getNo() << " :\n"
         << "   width = " << width << "\n"
         << "   height =  " << height << "\n"
         << "   area = " << getArea() << "\n"
         << "   leftUp point = " << leftUp << endl;
}

void Circle::print()
{
    cout << "Circle " << getNo() << " :\n"
         << "   radius = " << radius << "\n"
         << "   area = " << getArea() << "\n"
         << "   center  point = " << center << endl;
}


static int getRandom()
{
    return rand()%10 + 1;
}

Shape* RectangleFactory::createShape(int no)
{
    int width = getRandom();
    int height = getRandom();
    int x = getRandom();
    int y = getRandom();
    return new Rectangle(no, width, height, x, y);
}


Shape* CircleFactory::createShape(int no)
{
    int radius = getRandom();
    Point center(getRandom(), getRandom());
    return new Circle(no, radius, center);
}

void deleteShapes(Shape[] shapes, int size)
{

}

