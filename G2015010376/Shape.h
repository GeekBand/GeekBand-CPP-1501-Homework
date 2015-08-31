//
// Created by Sam Lau on 8/9/15.
//

#ifndef G2015010376_SHAPE_H
#define G2015010376_SHAPE_H


class Shape {
public:
    // 构造函数
    Shape(const int no = 0)
            : no_(no) {}

    // 析构函数
    virtual ~Shape() {};

    // setters和getters
    int no() const { return no_; }
    void set_no(int no) { no_ = no; }

protected:
    int no_;
};


#endif //G2015010376_SHAPE_H
