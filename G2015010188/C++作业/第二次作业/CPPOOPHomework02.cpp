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
	//����10��Rectangle��Circle
	Shape *shapes[20];
	for (size_t i = 0; i < 10; i++) {
		shapes[i] = new Rectangle(getRand(), getRand(), Point(0, 0));
	}
	for (size_t i = 10; i < 20; i++) {
		shapes[i] = new Circle(getRand(), Point(0, 0));
	}
		//��ӡ����
	std::cout << "����������Shape�������";
	for (int i = 0; i < 20; i++) {
		std::cout << shapes[i]->getArea() << " ";
	}
	std::cout << std::endl;
	//�������

	//���ú���ɸѡ
	Shape **TrueShapes = ReturnRightShapes(shapes, 20, [](Shape *shape) {return shape->getArea() < 50; });

	//��ɸѡ�����ӡ����
	int i = 0;
	Shape* shap = TrueShapes[0];
	std::cout << "���з��Ϲ���������";
	while (shap != nullptr) {
		std::cout << shap->getArea() << " ";
		shap = TrueShapes[++i];
	}

	//�ͷ��ڴ�
	Shape **pShapes = shapes;

	delete[] pShapes;
	pShapes = nullptr;
	delete[] TrueShapes;
	TrueShapes = nullptr;
	getchar();

	return 0;
}

