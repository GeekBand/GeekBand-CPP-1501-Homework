// CPPOOPHomework02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include <random>
#include <iostream>
int getRand(int a = 1, int b = 10) {
	return (rand() % (b - a + 1)) + a;
}

template <typename Func>
Shape **ReturnRightShapes(Shape *shapes[], int size, Func fun) {
	int i, j;
	for (i = 0, j = size; i < j;) {
		if (fun(shapes[i])) {
			std::swap(shapes[i], shapes[--j]);
		}
		else {
			++i;
		}
	}
	Shape **TrueShapes = new Shape*[j + 1];
	for (i = 0; i < j; i++) {
		TrueShapes[i] = Shape::findAndClone(shapes[i]->getType(), shapes[i]);
	}
	TrueShapes[j] = nullptr;
	return TrueShapes;
}
int main() {
	//创建10个Rectangle和Circle
	Shape *shapes[20];
	for (size_t i = 0; i < 10; i++) {
		shapes[i] = new Rectangle(getRand(), getRand(), Point(0, 0));
	}
	for (size_t i = 10; i < 20; i++) {
		shapes[i] = new Circle(getRand(), Point(0, 0));
	}
		//打印出来
	std::cout << "创建的所有Shape的面积：";
	for (int i = 0; i < 20; i++) {
		std::cout << shapes[i]->getArea() << " ";
	}
	std::cout << std::endl;
	//创建完成

	//调用函数筛选
	Shape **TrueShapes = ReturnRightShapes(shapes, 20, [](Shape *shape) {return shape->getArea() < 50; });

	//把筛选结果打印出来
	int i = 0;
	Shape* shap = TrueShapes[0];
	std::cout << "所有符合规则的面积：";
	while (shap != nullptr) {
		std::cout << shap->getArea() << " ";
		shap = TrueShapes[++i];
	}

	//释放内存
	for (int i = 0; i < 20; ++i) {
		delete shapes[i];
		shapes[i] = nullptr;
	}
	delete[] TrueShapes;
	TrueShapes = nullptr;
	getchar();

	return 0;
}

