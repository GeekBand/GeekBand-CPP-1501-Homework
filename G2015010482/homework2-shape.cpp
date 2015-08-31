#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "homework2-shape.h"
using namespace std;


int main()
{
	//rand()*10;
	Shape* a[20];
	for(int i = 0; i < 10; i++)
	{
		int temp1,temp2,temp3;
		while(!(temp1=rand()%10));
		while(!(temp2=rand()%10));
		while(!(temp3=rand()%10));
		a[i] = new Circle(temp1,temp2,temp3);
	}
	for (int i = 10; i < 20; i++)
	{
		int temp1,temp2,temp3,temp4;
		while(!(temp1=rand()%10));
		while(!(temp2=rand()%10));
		while(!(temp3=rand()%10));
		while(!(temp4=rand()%10));
		a[i] = new Rectangle(temp1,temp2,temp3,temp4);
	}
	for (int i = 0; i < 20 ; i++)
	{
		cout << i << " shape's area = " << a[i]->getArea()<<'\n';
		a[i]->printTest();
	}

	cout<<"**************Below is results***************\n";
	Shape *b[20];
	for (int i = 0,j=0; i < 20 ; i++)
	{
		if(a[i]->getArea() >= 50)
		{
			b[j] = a[i];
			j++;
		}
	}
	for(int i = 0; b[i]!=NULL; i++)
	{
		cout << i << " shape's area = " << b[i]->getArea()<<'\n';
		b[i]->printTest();
	}
	return 0;
}