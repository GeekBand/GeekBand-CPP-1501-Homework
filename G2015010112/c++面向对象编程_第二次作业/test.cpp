#include <iostream>  
#include "Circle.h"  
#include "Rectangle.h"	  

using namespace std;

#define RANDUM rand() % 10 + 1

Shape** Prosess()
{
	const int rCount = 10;
	const int cCount = 10;
	const int totalCount = rCount + cCount;
	//这个数组属于函数内部的局部变量，因此放在了函数的栈中
	//当函数运行结束时，随着函数栈的自动解退，该数组所占内存自动消失
	Shape* shapes[totalCount];
	int index = 0;

	for (int i = 0; i < rCount && index < totalCount; i++, index++)
	{
		shapes[index] = new Rectangle(RANDUM, RANDUM, RANDUM, RANDUM);
	}

	for (int i = 0; i < cCount && index < totalCount; i++, index++)
	{
		shapes[index] = new Circle(RANDUM, RANDUM, RANDUM);
	}

	int resultCount = totalCount;
	for (int i = 0; i < totalCount; i++)
	{
		if (shapes[i]->getArea() < 50)
		{
			delete shapes[i];
			shapes[i] = nullptr;
			resultCount--;
		}
	}

	index = 0;
	//这个数组是在堆中分配的，当函数结束运行时，这个数组所占的空间依然存在
	Shape** resultShapes = new Shape*[resultCount + 1];
	for (int i = 0; i < totalCount && index < resultCount; i++)
	{
		//将面积大于50的图形存起来
		if (shapes[i] != nullptr)
		{
			resultShapes[index] = shapes[i];
			index++;
		}
	}

	resultShapes[resultCount] = 0;

	return resultShapes;
}

int main(void)
{
	Shape** shapes = Prosess();

	for (int i = 0; shapes[i] != nullptr; i++)
	{
		cout << "面积大于50的图形的面积如下：" << shapes[i]->getArea() << endl;

	}
	for (int i = 0; shapes[i] != nullptr; i++)
	{
		delete shapes[i];//删除数组shapes中，存放的元素所占的内存
	}
	delete [] shapes;//删除数组shapes本身占用的内存

	system("pause");

	return 0;
}

