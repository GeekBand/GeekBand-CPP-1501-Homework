/*************************************************************************
	> File Name: main.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: 2015年08月14日 星期五 15时04分50秒
 ************************************************************************/

#include<iostream>
#include"Rectangle.h"
using namespace std;

int main()
{
    //检测构造函数和"<<"运算符
    cout << "input x, y, width, height:";
    int x, y, width, height;
    cin >> x >> y >> width >> height;
    Rectangle* r = new Rectangle(width, height, x, y);
    cout << *r << endl;

    //检测拷贝构造函数
    Rectangle* r1 = new Rectangle(*r);
    cout << *r1 << endl;
    //检测赋值构造函数
    Rectangle r2 = *r1;
    cout << r2 << endl;
    //检测计数器
    delete r;
    cout << *r1 << endl;
    return 0;
}

