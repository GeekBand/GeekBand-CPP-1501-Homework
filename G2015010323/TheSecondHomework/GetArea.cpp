#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "GetArea.h"
using namespace std;

int main()
{
	Shape* p[20];
	Shape* t;
	int x,y;
	int width,height;
	int radius;
	int i;
	int len;

	srand( (unsigned)time(NULL) );

	for(i = 0 ; i < 20; i++)
	{
		x = rand()%10;
		y = rand()%10;
		if(i < 10)
		{
			width = rand()%10;
			height = rand()%10;
			p[i] = new Rectangle(i,width,height,x,y);
		}else
		{
			radius = rand()%10;
			p[i] = new Circle(i,radius,x,y);
		}
	}

	cout<<"Area before deleting:"<<endl;

	for(i = 0 ; i < 20; i++)
	{
		printf("area = %.2lf  no = %d\n",p[i]->getArea(),p[i]->getNo());
	}

	len = 0;

	for(i = 0 ; i < 20; i++)
	{
		if(p[i]->getArea() < 50.0)
		{
			delete p[i];
			p[i] = nullptr;

		}else
		{
			p[len] = p[i];
			len++;
			p[i] = nullptr;
		}
	}

	cout<<"Area after delete:"<<endl;

	for(i = 0 ; i < len; i++)
	{
		printf("area = %.2lf  no = %d\n",p[i]->getArea(),p[i]->getNo());
	}

	for(i = 0 ; i < len; i++)
	{
		delete p[i];
		p[i] = nullptr;
	}
	return 0;
}
