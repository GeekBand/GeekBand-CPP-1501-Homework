#ifndef __XUN_POINT__
#define __XUN_POINT__

class Point {
public:
    Point(int _x = 0, int _y = 0): x(_x), y(_y) { };
    Point(const Point& other);
    Point& operator = (const Point& other);
    ~Point() { };
    int xVal() const { return x; }
    int yVal() const { return y; }
private:
    int x;
    int y;
};

inline
Point& Point::operator = (const Point& other)
{
    if (this == &other)
        return *this;
    
    this->x = other.xVal();
    this->y = other.yVal();
    
    return *this;
}

#endif