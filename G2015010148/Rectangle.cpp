#include<iostream.h>
#include"myrectangle.h"

void main()
{
	Rectangle rect1(100,200,50,30);
	cout<<"Rectangle leftup of point:"<<endl;
	cout<<"coordination:";
	cout<<"("<<rect1.leftUp->x<<","<<rect1.leftUp->y<<")"<<endl;

	cout<<"Rectangle rightDown of point:"<<endl;
	cout<<"coordination:";
    cout<<"("<<rect1.rightDown->x<<","<<rect1.rightDown->y<<")"<<endl;

	cout<<"---------------------------------"<<endl;

	Rectangle rect2(rect1);
	cout<<"Rectangle leftup of point:"<<endl;
	cout<<"coordination:";
	cout<<"("<<rect2.leftUp->x<<","<<rect2.leftUp->y<<")"<<endl;
    cout<<"Rectangle rightDown of point:"<<endl;
	cout<<"coordination:";
	cout<<"("<<rect2.rightDown->x<<","<<rect2.rightDown->y<<")"<<endl;

	cout<<"---------------------------------"<<endl;

	Rectangle rect3(3,3,3,3);
	rect3 = rect1;
	cout<<"Rectangle leftup of point:"<<endl;
	cout<<"coordination:";
	cout<<"("<<rect3.leftUp->x<<","<<rect3.leftUp->y<<")"<<endl;
    cout<<"Rectangle rightDown of point:"<<endl;
	cout<<"coordination:";
	cout<<"("<<rect3.rightDown->x<<","<<rect3.rightDown->y<<")"<<endl;

};