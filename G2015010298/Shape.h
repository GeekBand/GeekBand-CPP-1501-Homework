#ifndef __XUN_SHAPE__
#define __XUN_SHAPE__

class Shape {
public:
    Shape() { ++no; }
    ~Shape() { --no; }
    int num() const { return no; }
private:
    int no;
};

#endif