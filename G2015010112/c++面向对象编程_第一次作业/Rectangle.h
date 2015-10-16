#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Shape.h"  
#include "Point.h"  

class Rectangle:public Shape 
{
public:
	//构造函数中的参数的名字，不要与成员变量的名字相同
	//这里的成员初始化列表中，不需要写Shape()，因为会自动调用这个函数
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

//对于拷贝构造函数，
//(1)大括号里边只写对于指针变量的成员的处理，不要对其他的成员进行处理
//(2)其他的成员的处理，放到初始化列表中进行--如何书写初始化成员列表：按照成员的实际初始化顺序，进行书写初始化成员列表
//(3)拷贝构造函数是用来创建对象的，所以this指向的对象是不存在的（我们要构造的对象），other指向的对象是已经存在的（以这个对象为范本来创建对象）
//(4)所以我们只需要考虑other指向的对象中的指针变量成员：other.leftUp;是否为空
//(5)如何书写拷贝构造函数：画出子类Rectangle对象的内存模型，根据内存模型考虑如何书写
Rectangle::Rectangle(const Rectangle& other):
	Shape(other), width(other.width), height(other.height)
{
	if (other.leftUp != nullptr)
	{
		this->leftUp = new Point(*other.leftUp);//point类发生改变时，这里也不用修改--这里需使用拷贝构造函数point
	}
	else//(other.leftUp == nullptr)
	{
		this->leftUp = nullptr;//这一步是十分重要的：不为this.leftUp附上空值，默认会变成随机值，
		                       //如果此时使用delete this.leftUp；会导致一个不确定的内存单元被释放掉
	}
}
//对于赋值运算符
//如何书写赋值运算符：画出子类Rectangle对象的内存模型，根据内存模型考虑如何书写
//由于赋值运算符两侧的对象是已经存在的，所以在书写时需要考虑如下四种情况：
//(1)this->leftUp != nullptr && other.leftUp != nullptr
//(2)this->leftUp == nullptr && other.leftUp != nullptr
//(3)this->leftUp != nullptr && other.leftUp == nullptr
//(4)this->leftUp == nullptr && other.leftUp == nullptr
Rectangle& Rectangle::operator=(const Rectangle& other)
{
	//处理自我赋值
	if (this == &other)
	{
		return *this;
	}

	//调用父类Shape的赋值操作符，来为other类中的父类Shape成员no进行赋值操作
	Shape::operator=(other);

	this->width = other.width;
	this->height = other.height;

	if (this->leftUp != nullptr && other.leftUp != nullptr)
	{
		*this->leftUp = *other.leftUp;//完成成员变量point* leftUp；所指的point对象的赋值
	}
	else
	{
		if (this->leftUp == nullptr && other.leftUp != nullptr)
		{
			*this->leftUp = new Point(*other.leftUp);//调用point类的拷贝构造函数，以对象other中的point对象为模板，拷贝构造一个新point对象
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
