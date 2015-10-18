#include <list>
#include <iostream>
#include "Notifier.h"
#include "Observer.h"
using namespace std;
int main()
{
	Notifier p1(1,2);
	Observer* so1 = new SubObserver1;
	Observer* so2 = new SubObserver2;

	// 添加观察者
	p1.AddObserver(so1);
	p1.AddObserver(so2);
	p1.SetX(11);
	p1.SetY(12);	

	// 删除观察者
	p1.RemoveObserver(so1);
	p1.RemoveObserver(so2);
	delete so1;
	delete so2;
	system("pause");
	return 0;
}