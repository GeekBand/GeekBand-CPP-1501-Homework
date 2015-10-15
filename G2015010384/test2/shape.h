#ifndef ___SHAPE_H_
#define ___SHAPE_H_

class shape
{
    int no;
public:
    void setNo(int _no) { no = _no; }
    int getNo() const { return no; }
    virtual int getArea() = 0;
};

#endif
