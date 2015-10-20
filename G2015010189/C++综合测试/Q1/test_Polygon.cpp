#include "Polygon.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	Point a(1,2),b(3,4),c(5,6),d(7,8);
	vector<Point*>v0,v1,v2,v3;
	v0.push_back(&a);
	v0.push_back(&b);
	v0.push_back(&c);
	v0.push_back(&d);

	// ���Թ��캯��
	Polygon polygon1(v0,1);
	v1 = polygon1.getPoints();

	// ���Կ������캯��
	Polygon polygon2(polygon1);
	v2 = polygon2.getPoints();

	// ���Ը�ֵ���캯��
	Polygon polygon3 = polygon2;
	v3 = polygon3.getPoints();
	for(int i = 0; i < v1.size();i++)
	{
		Point p1 = *v1[i];
		Point p2 = *v2[i];
		Point p3 = *v3[i];
		cout<<"���죺"<<v1[i]<<": "<<p1.GetX()<<", "<<p1.GetY()<<endl;
		cout<<"������"<<v2[i]<<": "<<p2.GetX()<<", "<<p2.GetY()<<endl;
		cout<<"��ֵ��"<<v3[i]<<": "<<(*v3[i]).GetX()<<", "<<(*v3[i]).GetY()<<endl;
	}
	system("pause");
	return 0;
}