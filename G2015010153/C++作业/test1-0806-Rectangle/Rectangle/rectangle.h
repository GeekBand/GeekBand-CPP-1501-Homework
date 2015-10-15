#ifndef __RECTANGEL__
#define __RECTANGEL__

#include <iostream>
#include "shape.h"
#include "point.h"

using namespace std;

namespace Geekband
{
	// �Ȼ� <�ڴ�ģ��>

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

	// �޲ι��캯�� => ȱʡ���캯��
	// ֻ���Լ�д��һ���вεĹ��캯�����������Ͳ�������Ĭ��ȱʡ���캯��


	// ��������ֻ��ָ���Ա��������ȫ�����ڳ�ֵ��
	inline
	Rectangle::Rectangle(const Rectangle& other)
		: Shape(other), width(other.width), height(other.height)
		// ����˳������д˳���޹�,�ȸ��������,���ఴ������˳����,����д�ɱ�׼˳��
	{
		// leftup Ĭ�������ֵ~
		if(other.leftUp == 0) { // nullptr
			leftUp = 0; // nullptr
		} else {
			// ��֤ ���z����ʱ������Ҫ�޸Ĵ��룬����copy ctr
			// this->leftUp = new Point(other.leftUp->X(), other.leftUp->Y());
			// ���������������Զ�����
			leftUp = new Point(*other.leftUp);
		}
	}

	inline
	Rectangle& Rectangle::operator =(const Rectangle& other) {
		// check self assignment
		if(this == &other) {
			return *this;
		}

		// delete nullptr; û����
		// ���� delete ����ָ��������

		// copy assignʱ��㣬�������ߵĶ����ǹ������
		// �κ�һ�����������α�֤��ʼ��֮���ڲ���ָ��Ҫô��0Ҫô��nullptr

		// ��ʾ���ø���copy assign
		// ���걸�������Ա����ֹ��������޸�
		// �����shape������
		// ǰͷ���Լ�this
		// ���ü̳������ĸ�ֵ������
		// ��ǰ��д~~ ֮��д����
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

		// ��ʾ����copy assign
		if(leftUp != 0 && other.leftUp != 0) {
			*leftUp = *other.leftUp; // !!!
		} else {
			if (leftUp == 0 && other.leftUp != 0) {
				leftUp = new Point(*other.leftUp);
			} else if (other.leftUp == 0 && leftUp != 0) {
				delete leftUp;
				// ����leftUp��Ϊ����ָ��
				leftUp = 0;
				// ���Բ�д����Ϊ��������������������û��
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
