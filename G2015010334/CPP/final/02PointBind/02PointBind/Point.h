#ifndef __POINT_H_
#define __POINT_H_

#include "boost/function.hpp"
#include "boost/bind.hpp"
#include "iostream"

using namespace boost;
using namespace std;

template<typename T>

class Event
{
	bool flag;

public:
	typedef boost::function<T> handle_type;
	handle_type Invoke;

	Event() :flag(false), Invoke()
	{

	}

	Event& operator= (const boost::function<T>& rhs)
	{
		this->Invoke = rhs;
		flag = true;
		return *this;
	}

	void Clear()
	{
		flag = false;
	}

	bool IsNull()
	{
		return !flag;
	}
};


class Point
{
	int x;
	int y;

public:
	Event<void(int)> UpdateXEvent;
	Event<void(int)> UpdateYEvent;

	Point(int input_x, int input_y) 
		: x(input_x), 
		  y(input_y)
	{
	}

	int X() const 
	{ 
		return x; 
	}

	int Y() const 
	{ 
		return y; 
	}

	void SetX(int input_x)
	{
		x = input_x;
		if (!UpdateXEvent.IsNull())
		{
			UpdateXEvent.Invoke(x);
		}
	}

	void SetY(int input_y)
	{
		y = input_y;
		if (!UpdateYEvent.IsNull())
		{
			UpdateYEvent.Invoke(y);
		}
	}
};

#endif

