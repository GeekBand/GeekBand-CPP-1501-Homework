#ifndef __NOTIFIER__
#define __NOTIFIER__
#include "Observer.h"
#include "Point.h"
#include <list>

using namespace std;
// 通知者，继承了Point类
class Notifier:public Point
{
	list<Observer*> observerList;
public:
	Notifier(int x,int y):Point(x,y){}
	~Notifier()
	{
	    while( ! observerList.empty())
		{
			observerList.pop_back();
		}
	}
	void SetX(int a)
	{
		Point oldPoint(GetX(),GetY());
		Point::SetX(a);
		Point newPoint(GetX(),GetY());
		Notice(oldPoint,newPoint);		
	}
	void SetY(int b)
	{
		Point oldPoint(GetX(),GetY());
		Point::SetY(b);
		Point newPoint(GetX(),GetY());
		Notice(oldPoint,newPoint);		
	}

	// 添加观察者
	void AddObserver(Observer* o)
	{
		observerList.push_back(o);
	}

	// 删除观察者
	void RemoveObserver(Observer* o)
	{
		observerList.remove(o);
	}

	// 发送通知
	void  Notice(Point& a, Point& b)
	{
		list<Observer*>::iterator itor = observerList.begin();
	    while(itor != observerList.end())
		{
			(*itor)->Response(a,b);
			itor++;
		}
	}
};
#endif