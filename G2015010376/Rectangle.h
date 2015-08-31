//
// Created by Sam Lau on 8/9/15.
//

#ifndef G2015010376_RECTANGLE_H
#define G2015010376_RECTANGLE_H

#include <profile.h>
#include "Point.h"
#include "Shape.h"

class Rectangle : public Shape{
public:
    // 构造函数
    Rectangle(const int x = 0, const int y = 0, const int width = 0, const int height = 0)
            :width_(width), height_(height)
    {
        left_up_ = new Point(x, y);
    }
    // 复制控制
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle();

    // setters和getters
    int width() const { return width_; }
    void set_width(int width) { width_ = width; }
    int height() const { return  height_; }
    void set_height(int height) { height_ = height; }
    Point* left_up() const { return left_up_; }
    void set_left_up(Point *left_up) { left_up_= left_up; }

private:
    int width_;
    int height_;
    Point* left_up_;
};

inline Rectangle::Rectangle(const Rectangle& other) {
    left_up_ = new Point(other.left_up()->x(), other.left_up()->x());
    width_ = other.width();
    height_ = other.height();
}

inline Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this == &other) {
        return *this;
    }

    delete left_up_;
    left_up_ = other.left_up();
    width_ = other.width();
    height_ = other.height();

    return *this;
}

inline Rectangle::~Rectangle() {
    delete left_up_;
}

#endif //G2015010376_RECTANGLE_H
