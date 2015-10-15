#ifndef __XUN_POINT__
#define __XUN_POINT__

class Point {
public:
    Point(int _x = 0, int _y = 0): x(_x), y(_y) { };
private:
    int x;
    int y;
};

#endif