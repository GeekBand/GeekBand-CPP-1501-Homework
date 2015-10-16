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
	//����������ں����ڲ��ľֲ���������˷����˺�����ջ��
	//���������н���ʱ�����ź���ջ���Զ����ˣ���������ռ�ڴ��Զ���ʧ
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
	//����������ڶ��з���ģ���������������ʱ�����������ռ�Ŀռ���Ȼ����
	Shape** resultShapes = new Shape*[resultCount + 1];
	for (int i = 0; i < totalCount && index < resultCount; i++)
	{
		//���������50��ͼ�δ�����
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
		cout << "�������50��ͼ�ε�������£�" << shapes[i]->getArea() << endl;

	}
	for (int i = 0; shapes[i] != nullptr; i++)
	{
		delete shapes[i];//ɾ������shapes�У���ŵ�Ԫ����ռ���ڴ�
	}
	delete [] shapes;//ɾ������shapes����ռ�õ��ڴ�

	system("pause");

	return 0;
}

