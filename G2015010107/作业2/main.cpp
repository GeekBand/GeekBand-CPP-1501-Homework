#include "Rectangle.h"
#include <iostream>
#include <time.h>
#include "Shape.h"
#include <stdlib.h>
using namespace std;
 
Shape* Return(){
	srand((int)time(NULL)); //ʱ������ 
	Shape** a=new Shape*[20];
	for(int i=0;i<20;i++){  //����
		if(i<10){
			a[i] = new Rectangle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);		
		}
		else {
			a[i] = new Circle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
		}
	}
	Shape** b=new Shape*[20];   //������
	int n = 0;   //����
	for (int i = 0; i < 20; i++) {  //ɾ�����С��50����״
		if (a[i]->getArea() < 50) {
			delete a[i];
		}
		else {
			b[n] = a[i];
			n++;
		}
	}
	
	return *b;	
}
int main() {
	Shape *b;
	b = Return();
	
	//���������  ��ô���
	
	getchar();
	return 0;
}









