#ifndef __RECTANGEL__
#define __RECTANGEL__

#include <iostream>
#include "shape.h"
#include "point.h"

using namespace std;

namespace Geekband
{
	// 先画 <内存模型>

	class Retangle;

	class Rectangle: public Shape {
		int width;
		int height;

		Point *leftUp;

	public:
		Rectangle();
		Rectangle(int width, int height, int x, int y, int no);
		Rectangle(const Rectangle& other);
		Rectangle& operator =(const Rectangle& other);
		~Rectangle();

		// for test
		void set_leftup(Point* leftUp);
		Point* get_leftup() const;

		friend ostream& operator << (ostream& os, const Rectangle& rtl);
	};

	inline
		Rectangle::Rectangle()
		: Shape(0), width(0), height(0), leftUp(new Point(0, 0))
	{ }

	inline
	Rectangle::Rectangle(int width, int height, int x, int y, int no)
		: Shape(no), width(width), height(height), leftUp(new Point(x, y))
	{ }

	// 无参构造函数 => 缺省构造函数
	// 只有自己写了一个有参的构造函数，编译器就不会生成默认缺省构造函数


	// 大括号内只对指针成员处理，其他全部放在初值列
	inline
	Rectangle::Rectangle(const Rectangle& other)
		: Shape(other), width(other.width), height(other.height)
		// 调用顺序与书写顺序无关,先父类后子类,子类按照声明顺序来,尽量写成标准顺序
	{
		// leftup 默认是随机值~
		if(other.leftUp == 0) { // nullptr
			leftUp = 0; // nullptr
		} else {
			// 保证 添加z变量时，不需要修改代码，所以copy ctr
			// this->leftUp = new Point(other.leftUp->X(), other.leftUp->Y());
			// 三大函数，编译器自动生成
			leftUp = new Point(*other.leftUp);
		}
	}

	inline
	Rectangle& Rectangle::operator =(const Rectangle& other) {
		// check self assignment
		if(this == &other) {
			return *this;
		}

		// delete nullptr; 没问题
		// 但是 delete 悬浮指针有问题

		// copy assign时间点，左右两边的对象都是构造过的
		// 任何一个对象都有责任保证初始化之后内部的指针要么是0要么是nullptr

		// 显示调用父类copy assign
		// ！完备处理父类成员，防止父类代码修改
		// 必须加shape作用域
		// 前头可以加this
		// 调用继承下来的赋值操作符
		// 在前面写~~ 之后写子类
		/*this->*/Shape::operator = (other);

		width = other.width;
		height = other.height;

		/*
		if(other.leftUp == NULL) { // nullptr
			if(leftUp != NULL) {
				delete leftUp;
				leftUp = NULL;
			}
		} else {
			if(leftUp == NULL) {
				leftUp = new Point(other.leftUp->X(), other.leftUp->Y());
			} else {
				leftUp->X(other.leftUp->X());
				leftUp->Y(other.leftUp->Y());
			}
		}
		*/

		// 显示调用copy assign
		if(leftUp != 0 && other.leftUp != 0) {
			*leftUp = *other.leftUp; // !!!
		} else {
			if (leftUp == 0 && other.leftUp != 0) {
				leftUp = new Point(*other.leftUp);
			} else if (other.leftUp == 0 && leftUp != 0) {
				delete leftUp;
				// 避免leftUp成为悬浮指针
				leftUp = 0;
				// 可以不写，因为调用了析构函数，对象都没了
			}
		}

		return *this;
	}


	inline
	void Rectangle::set_leftup(Point* leftUp) {
		if(this->leftUp != 0) { // nullptr
			delete this->leftUp;
		}
		this->leftUp = leftUp;
	}
	
	inline
	Point* Rectangle::get_leftup() const {
		return this->leftUp;
	}

	inline
	Rectangle::~Rectangle() {
		// if(leftUp != NULL) { // nullptr
			delete leftUp;
		// }
	}

	ostream& operator << (ostream& os, const Rectangle& rtl) {
		if(rtl.get_leftup() == 0) {
			return cout << "[width : " << rtl.width << ", height : " << rtl.height << ", leftUp : NULL]";
		}
		return cout << "[width : " << rtl.width << ", height : " << rtl.height <<
			", leftUp : [x : " << rtl.leftUp->X() << ", y : " << rtl.leftUp->Y() << "]]";
	}

}


#endif
