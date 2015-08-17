#include "stdafx.h"
#include<iostream>
#include"shapes.h"
#include<time.h>

using namespace std;



Shape** Process(int &size){
	// 生成20个图形
	srand((unsigned)time(NULL));
	Shape *arr[20];
	for (int i = 0; i < 20; i++){
		if (i < 10){
			arr[i] = new Rectangle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
		}
		else{
			arr[i] = new Circle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
		}
	}

	// 对图形进行筛选
	size = 0;
	int index[20];
	for (int i = 0; i < 20; i++){
		//arr[i]->detail();
		if (arr[i]->getArea() >= 50){
			//cout << "ok" << endl;
			index[size] = i;
			size = size + 1;
		}
	}
	Shape**result = new Shape*[size];

	for (int i = 0; i < 20; i++){
		cout << index[i] << endl;
	}

	int n = 0;
	for (int i = 0; i < 20; i++){
		// 有用的放到result里面返回，没用的delete
		if (i == index[n]){
			cout << "save  " << i << endl;
			result[n] = arr[i];
			n++;
		}
		else{
			cout << "delete " << i << endl;
			delete arr[i];
		}
	}


	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0;
	Shape**p = Process(a);
	cout << "一共包含有效图形 " << a << " 个" << endl;
	/*
		do something
	*/
	for (int i = 0; i < a; i++){
		delete p[i];
	}	
}

