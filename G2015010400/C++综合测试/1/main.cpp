
#include <iostream>
#include "Polygon.h"

using std::cout;
using std::endl;


int main(int argc, const char * argv[]) {
    //构造函数，赋值符重载测试
    Point p1(0, 0);
    Point p2(2, 1);
    Point p3 = p2;
    Point p4(3, 3);
    Point p5(6, 2);
    Point p6(7, 5);
    Point P[4] = {p1, p2, p3, p4};
    Point T[3] = {p4, p5, p6};
    Polygon polygon(P, 4);
    Polygon temp(T, 3);
    Polygon polygon_copy(polygon);
    Polygon polygon_fuzhi = polygon;
    cout << polygon << endl;
    cout << polygon_copy << endl;
    cout << polygon_fuzhi << endl;
    //深拷贝测试
    polygon = temp;
    cout << polygon << endl;
    cout << polygon_copy << endl;
    cout << polygon_fuzhi << endl;
    //nullptr测试
    Polygon wrong(T, 2);
    Polygon wrong1(wrong);
    cout << wrong << endl;
    cout << wrong1 << endl;
    polygon_copy = wrong;
    cout << polygon_copy << endl;
    wrong = polygon;
    cout << wrong << endl;
    
    return 0;
}
