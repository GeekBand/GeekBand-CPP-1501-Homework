#include <iostream>

#include "Rectangle.h"

using namespace std;
int main()
{
	
	cout<<"\n**************"<<endl;
	cout<< "Test of ctor"<<endl;	
	Rectangle rectangle1(1,2,3,4);
	rectangle1.setNo(10);
	cout<<"no of rectangle1 is : "<<rectangle1.getNo()<<endl;
    cout<<"width of rectangle1 : "<<rectangle1.getWidth()<<endl;
	cout<<"height of rectangle1 : "<<rectangle1.getHeight()<<endl;    
    cout<<"x of point in rectangle1 : "<<rectangle1.getLeftUp()->getX()<<endl;
	cout<<"y of point in rectangle1 : "<<rectangle1.getLeftUp()->getY()<<endl;


	cout<<"\n**************"<<endl;
	cout<< "Test of copy ctor"<<endl;
    Rectangle rectangle2(rectangle1);
	cout<<"no of rectangle2 is : "<<rectangle2.getNo()<<endl;
    cout<<"width of rectangle2 : "<<rectangle2.getWidth()<<endl;
	cout<<"height of rectangle2 : "<<rectangle2.getHeight()<<endl;
    cout<<"x of point in rectangle2 : "<<rectangle2.getLeftUp()->getX()<<endl;
	cout<<"y of point in rectangle2 : "<<rectangle2.getLeftUp()->getY()<<endl;



	cout<<"\n**************"<<endl;
	cout<< "Test of assignment"<<endl;
	rectangle1.setNo(20);
	rectangle1.setWidth(21);
	rectangle1.setHeight(22);
	rectangle1.getLeftUp()->setX(23);
	rectangle1.getLeftUp()->setY(24);
	cout<<"no of rectangle1 is : "<<rectangle1.getNo()<<endl;
    cout<<"width of rectangle1 : "<<rectangle1.getWidth()<<endl;
	cout<<"height of rectangle1 : "<<rectangle1.getHeight()<<endl;    
    cout<<"x of point in rectangle1 : "<<rectangle1.getLeftUp()->getX()<<endl;
	cout<<"y of point in rectangle1 : "<<rectangle1.getLeftUp()->getY()<<endl;

	cout<< "\nafter assignment"<<endl;
	rectangle2 = rectangle1;
	cout<<"no of rectangle2 is : "<<rectangle2.getNo()<<endl;
    cout<<"width of rectangle2 : "<<rectangle2.getWidth()<<endl;
	cout<<"height of rectangle2 : "<<rectangle2.getHeight()<<endl;
    cout<<"x of point in rectangle2 : "<<rectangle2.getLeftUp()->getX()<<endl;
	cout<<"y of point in rectangle2 : "<<rectangle2.getLeftUp()->getY()<<endl;


	return 0;
}
