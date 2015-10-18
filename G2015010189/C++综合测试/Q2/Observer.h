#ifndef __OBSERVER__
#define __OBSERVER__
#include "Point.h"
using namespace std;
class Observer
{
public:
	virtual void Response(Point& a, Point& b)=0;
	virtual ~Observer(){}
};

class SubObserver1:public Observer
{
public:
	virtual void Response(Point& a, Point& b)
	{
		cout<<"Point changes from:("<<a.GetX()<<", "<<a.GetY()<<"),to ("<<b.GetX()<<", "<<b.GetY()<<")"<<endl;
	}
};

class SubObserver2:public Observer
{
	virtual void Response(Point& a, Point& b)
	{
		cout<<"("<<a.GetX()<<", "<<a.GetY()<<") -> ("<<b.GetX()<<", "<<b.GetY()<<")"<<endl;
	}
};

#endif