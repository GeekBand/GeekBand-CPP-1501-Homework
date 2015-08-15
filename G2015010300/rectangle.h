//
// Created by diaosj on 15/8/8.
//

#ifndef GEEKBANDTEST_RECTANGLE_H
#define GEEKBANDTEST_RECTANGLE_H

class Rectangle : public Shape {
    int width;
    int height;

    Point *leftUp;

public:
    Rectangle(const int width, const int height, const int x, const int y);

    Rectangle(const Rectangle &other);

    Rectangle &operator=(const Rectangle &other);

    ~Rectangle();

    int getWidth() const { return width; }

    int getHeight() const { return height; }

    Point getLeftUp() const { return *leftUp; }
};

inline Rectangle::Rectangle(const int width, const int height, const int x, const int y) {
    //unsigned int
    this->width = (width > 0) ? width : 0;
    this->height = (height > 0) ? height : 0;
    this->leftUp = new Point(x, y);
}


inline Rectangle::Rectangle(const Rectangle &other) :
        width(other.width),
        height(other.height),
        Shape(other) {
    if (other.leftUp != nullptr) {
        leftUp = new Point(*other.leftUp);
    }
    else {
        leftUp = nullptr;
    }
}


inline Rectangle &Rectangle::operator=(const Rectangle &other) {
    if (this == &other) {
        return *this;
    }

    this->Shape::operator=(other);
    this->width = other.width;
    this->height = other.height;

    //delete this->leftUp;
    if (other.leftUp != nullptr) {
        if (leftUp != nullptr) {
            *leftUp = *other.leftUp;
        }
        else {
            leftUp = new Point(*other.leftUp);
        }
    }
    else {
        delete leftUp;
        leftUp = nullptr;
    }
    return *this;
}


inline Rectangle::~Rectangle() {
    delete leftUp;
    leftUp = nullptr;
}

#endif //GEEKBANDTEST_RECTANGLE_H
