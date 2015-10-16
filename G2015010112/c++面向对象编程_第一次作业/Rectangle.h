#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Shape.h"  
#include "Point.h"  

class Rectangle:public Shape 
{
public:
	//���캯���еĲ��������֣���Ҫ���Ա������������ͬ
	//����ĳ�Ա��ʼ���б��У�����ҪдShape()����Ϊ���Զ������������
	Rectangle(int _width, int _height, int _x, int _y): 
		width(_width), height(_height), leftUp(new Point(_x, _y)) {};
	Rectangle(const Rectangle& other);
	virtual ~Rectangle();
	Rectangle& operator=(const Rectangle& other);

private:
	int width;
	int height;

	Point* leftUp;
};

//���ڿ������캯����
//(1)���������ֻд����ָ������ĳ�Ա�Ĵ�����Ҫ�������ĳ�Ա���д���
//(2)�����ĳ�Ա�Ĵ����ŵ���ʼ���б��н���--�����д��ʼ����Ա�б����ճ�Ա��ʵ�ʳ�ʼ��˳�򣬽�����д��ʼ����Ա�б�
//(3)�������캯����������������ģ�����thisָ��Ķ����ǲ����ڵģ�����Ҫ����Ķ��󣩣�otherָ��Ķ������Ѿ����ڵģ����������Ϊ��������������
//(4)��������ֻ��Ҫ����otherָ��Ķ����е�ָ�������Ա��other.leftUp;�Ƿ�Ϊ��
//(5)�����д�������캯������������Rectangle������ڴ�ģ�ͣ������ڴ�ģ�Ϳ��������д
Rectangle::Rectangle(const Rectangle& other):
	Shape(other), width(other.width), height(other.height)
{
	if (other.leftUp != nullptr)
	{
		this->leftUp = new Point(*other.leftUp);//point�෢���ı�ʱ������Ҳ�����޸�--������ʹ�ÿ������캯��point
	}
	else//(other.leftUp == nullptr)
	{
		this->leftUp = nullptr;//��һ����ʮ����Ҫ�ģ���Ϊthis.leftUp���Ͽ�ֵ��Ĭ�ϻ������ֵ��
		                       //�����ʱʹ��delete this.leftUp���ᵼ��һ����ȷ�����ڴ浥Ԫ���ͷŵ�
	}
}
//���ڸ�ֵ�����
//�����д��ֵ���������������Rectangle������ڴ�ģ�ͣ������ڴ�ģ�Ϳ��������д
//���ڸ�ֵ���������Ķ������Ѿ����ڵģ���������дʱ��Ҫ�����������������
//(1)this->leftUp != nullptr && other.leftUp != nullptr
//(2)this->leftUp == nullptr && other.leftUp != nullptr
//(3)this->leftUp != nullptr && other.leftUp == nullptr
//(4)this->leftUp == nullptr && other.leftUp == nullptr
Rectangle& Rectangle::operator=(const Rectangle& other)
{
	//�������Ҹ�ֵ
	if (this == &other)
	{
		return *this;
	}

	//���ø���Shape�ĸ�ֵ����������Ϊother���еĸ���Shape��Աno���и�ֵ����
	Shape::operator=(other);

	this->width = other.width;
	this->height = other.height;

	if (this->leftUp != nullptr && other.leftUp != nullptr)
	{
		*this->leftUp = *other.leftUp;//��ɳ�Ա����point* leftUp����ָ��point����ĸ�ֵ
	}
	else
	{
		if (this->leftUp == nullptr && other.leftUp != nullptr)
		{
			*this->leftUp = new Point(*other.leftUp);//����point��Ŀ������캯�����Զ���other�е�point����Ϊģ�壬��������һ����point����
		}
		else//(1) (this->leftUp != nullptr && other.leftUp == nullptr)
		{   //(2) (this->leftUp == nullptr && other.leftUp == nullptr)
			delete this->leftUp;
			this->leftUp = nullptr;
		}
	}
	return *this;
}

Rectangle::~Rectangle()
{
	delete leftUp;
	leftUp = nullptr;
}

#endif // _RECTANGLE_H_
