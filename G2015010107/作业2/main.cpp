#include "Rectangle.h"
#include <iostream>
#include <time.h>
#include "Shape.h"
#include <stdlib.h>
using namespace std;
 
Shape* Return(){
	srand((int)time(NULL)); //时间种子 
	Shape** a=new Shape*[20];
	for(int i=0;i<20;i++){  //生成
		if(i<10){
			a[i] = new Rectangle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);		
		}
		else {
			a[i] = new Circle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
		}
	}
	Shape** b=new Shape*[20];   //新数组
	int n = 0;   //记数
	for (int i = 0; i < 20; i++) {  //删除面积小于50的形状
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
	
	//不能输出啊  怎么输出
	
	getchar();
	return 0;
}









