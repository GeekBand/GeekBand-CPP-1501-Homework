//
// Created by diaosj on 15/8/11.
//

#ifndef GEEKBANDTEST_POINT_H
#define GEEKBANDTEST_POINT_H

class Point {
    int x;
    int y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) { }

    int getX() const { return x; }

    int getY() const { return y; }

    Point(const Point &rhs) {
        x = rhs.x;
        y = rhs.y;
    }

    const Point &operator=(const Point &rhs) {
        if (this == &rhs) {
            return *this;
        }

        x = rhs.x;
        y = rhs.y;
    }
};

#endif //GEEKBANDTEST_POINT_H
