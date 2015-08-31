#ifndef __SHAPE__
#define __SHAPE__

int g_no = 0;

class Shape
{
    int no;

public:
    Shape() {no = ++g_no;}
    ~Shape() {}
};

#endif

