#include <iostream>
#include "Shape.h"

using namespace std;

Shape** getShapeAreaArray(int& fit_size)  // fit_size: 删除 area 小于50后保存的新数组的大小
{
	// 初始化随机种子
	srand(time(0));

	const int arrSize = 20;
	Shape* shapeArr[arrSize];  // 保存Shape*的数组
	for (int i = 0; i < 10; ++i) {
		// 生成随机数组
		int randNum[9];
		for (int j = 0; j < 9; ++j) {
			randNum[j] = rand()%10+1;
		}

		// Rectangle
		Rectangle* rec = new Rectangle(randNum[0], randNum[1], randNum[2], Point(randNum[3], randNum[4]));
		shapeArr[i*2] = rec;

		// Circle
		Circle* cir = new Circle(randNum[5], randNum[6], Point(randNum[7], randNum[8]));
		shapeArr[i*2+1] = cir;
	}

	// 删除 area 小于50的
	fit_size = arrSize;
	for (int i = 0; i < arrSize; ++i) {
		if (shapeArr[i]->getArea() < 50) {
			delete shapeArr[i];
			shapeArr[i] = NULL;
			--fit_size;
		}
	}

	// 新数组
	// Shape* newShapeArr[fit_size];
	Shape** newShapeArr = new Shape*[fit_size];  // newShapeArr 是一个指向 Shape* 的指针，即一个元素为 Shape* 的数组的首元素地址
	int cnt = 0;
	for (int i = 0; i < arrSize; ++i) {
		if (shapeArr[i]) {
			newShapeArr[cnt++] = shapeArr[i];
		}
	}

	return newShapeArr;

}

int main()
{
	int fit_size = 0;
	Shape** newShapeArr = getShapeAreaArray(fit_size);

	for (int i = 0; i < fit_size; ++i) {
		cout << newShapeArr[i]->getArea() << endl;
	}


	// delete newShapeArr;
	for (int i = 0; i < fit_size; ++i) {
		if (newShapeArr[i]) {
			delete newShapeArr[i];
			newShapeArr[i] = NULL;
		}
	}
	delete[] newShapeArr;

	return 0;
}