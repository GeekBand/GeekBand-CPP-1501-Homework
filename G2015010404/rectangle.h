#ifndef RECTANGLE_H
#define RECTANGLE_H
class Shape
{
    int no;
};
class Point
{
    int x;
    int y;
public:
    Point(int x, int y):x(x),y(y) {}
};

class Rectangle : public Shape
{
    int width;
    int height;

    Point *leftUp;
public:
    Rectangle():width(0),height(0),leftUp(nullptr){}
    Rectangle(int width, int height, int x, int y);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);

    ~Rectangle();
};
#endif // RECTANGLE_H
