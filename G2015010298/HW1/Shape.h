#ifndef __XUN_SHAPE__
#define __XUN_SHAPE__

class Shape {
public:
    Shape(int _no = 0): no(_no) { }
    virtual ~Shape() { } // must add virtual in base class's desctructor
private:
    int no;
};

#endif