//
// Created by Sam Lau on 8/9/15.
//

#ifndef G2015010376_POINT_H
#define G2015010376_POINT_H

class Point {
public:
    // 构造函数
    Point(const int x = 0, const int y = 0)
            : x_(x), y_(y) {}

    // setters和getters
    int x() const { return x_; }
    void set_x(int x) { x_ = x; }

    int y() const { return y_; }
    void set_y(int y) { y_ = y; }

private:
    int x_;
    int y_;
};


#endif //G2015010376_POINT_H
