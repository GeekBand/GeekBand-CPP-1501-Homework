// stdafx.cpp : source file that includes just the standard includes
// homework2.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <iostream>
#include "Shape_hw2.h"
using namespace std;

void createShape(Shape* a[], const int n)
{
	 for(int k = 0; k < (int)(n/2); k++)
	 {
		 Point p(rand() % 10 + 1, rand() % 10 + 1);
		 a[k] = new Rectangle(k, (int)(rand() % 10 + 1), (int)(rand() % 10 + 1), p);
	 }
	 for(int k = (int)(n/2); k < n; k++)
	 {
		 Point p(rand() % 10 + 1, rand() % 10 + 1);
		 a[k] = new Circle(k, (int)(rand() % 10 + 1), p);
	 }
	 a[n] = nullptr;
}

// 删除面积小于shapeArea的图形
Shape** removeFun(Shape* a[], const double shapeArea)
{
	int k = 0, newArrayLen = 0;
	while(a[k] != nullptr)
	{
		if(a[k]->getArea() >= shapeArea)
		{
			newArrayLen++;
		}
		else
		{
			delete a[k];
			a[k] = nullptr;
		}
		k++;
	}
	Shape** newArray = new Shape*[newArrayLen + 1];
	int cnt = 0;
	for(int i = 0; i < k; i++)
	{
		if(a[i] != nullptr)
		{
			newArray[cnt++] = a[i];
		}
	}
	newArray[cnt] = nullptr;
	return newArray;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Shape* pShape[21];
	
	createShape(pShape, 20);
	for(int k = 0; k < 20; k++)
	{
		if(k == 10)
			cout<<endl;
		cout<<k<<": "<<pShape[k]->getArea();
		cout<<"  ";
	}
	cout<<endl;

	Shape** Shape2 = removeFun(pShape, 50);
	int j = 0;
	cout<<"面积大于50的图形："<<endl;
	while(Shape2[j] != nullptr)
	{
		cout<<j<<": "<<Shape2[j]->getArea();
		cout<<"  ";
		j++;
	}
	cout<<endl;

	// 释放内存
	for(j = j-1; j >= 0; j--)
	{
		delete Shape2[j];
		Shape2[j] = nullptr;
	}
	delete[] Shape2;
	Shape2 = nullptr;
	system("pause");
	return 0;
}
