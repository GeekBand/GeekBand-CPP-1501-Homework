#include "stdafx.h"
#include<iostream>
#include"shapes.h"
#include<time.h>

using namespace std;

Shape** Process(int &size){
	const int arr_size = 20;
	// ����20��ͼ��
	srand((unsigned)time(NULL));
	Shape *arr[arr_size];
	for (int i = 0; i < arr_size; i++){
		if (i < 10){
			arr[i] = new Rectangle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
		}
		else{
			arr[i] = new Circle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
		}
	}

	// ��ͼ�ν���ɸѡ����¼��������Ҫ��ͼ����arr�е��±�
	size = 0;
	int index[arr_size];
	for (int i = 0; i < arr_size; i++){
		if (arr[i]->getArea() >= 50){
			// ����Ҫ�󣬼�¼����
			index[size] = i;
			size += 1;
		}
	}
	Shape**result = new Shape*[size];

	int n = 0;
	for (int i = 0; i < arr_size; i++){
		// ����Ҫ��ķŵ�result���淵�أ�û�õ�delete
		if (i == index[n]){
			// save
			result[n] = arr[i];
			n++;
		}
		else{
			// delete
			delete arr[i];
		}
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0;
	Shape**p = Process(a);
	// ����Ҫ���ͼ�θ�����a��
	// do something
	for (int i = 0; i < a; i++){
		p[i]->detail();
	}
	// delete
	for (int i = 0; i < a; i++){
		delete p[i];
	}
}