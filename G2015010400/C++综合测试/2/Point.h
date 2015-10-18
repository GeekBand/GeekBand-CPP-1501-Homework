//
//  Point.h
//  testproject
//
//  Created by Gutierrez on 15/10/10.
//  Copyright © 2015年 Gutierrez. All rights reserved.
//

#ifndef Point_h
#define Point_h

#include "Iprogress.h"
#include "Commandline.h"

class Point 
{
public:
    Point(int x_ = 0, int y_ = 0, Iprogress* ob = nullptr) : x(x_), y(y_), m_iprogress(ob) {}
    int getx() const {return x;}
    int gety() const {return y;}
    void setx(const int& x_);
    void sety(const int& y_);
    void setObserver(Iprogress* ob);
    Point& operator = (const Point& r);
private:
    int x,y;
    Iprogress* m_iprogress;
};

void Point::setx(const int& x_)
{
    int old = x;
    int now = x_;
    if (m_iprogress) {
        m_iprogress->doprogress(old, now);
    }
    x = x_;
}

void Point::sety(const int& y_)
{
    if (m_iprogress) {
        m_iprogress->doprogress(y, y_);
    }
    y = y_;
}

void Point::setObserver(Iprogress* ob)
{
    m_iprogress = ob;
}

Point& Point::operator = (const Point& r)
{
    setx(r.getx());
    sety(r.gety());
    return *this;
}

std::ostream& operator << (std::ostream& os, const Point& r)
{
    os << "(" << r.getx() << "," << r.gety() << ")" ;
    return os;
}
#endif /* Point_h */
