#ifndef __POLYGON__
#define __POLYGON__

#include <vector>
using namespace std;
class Shape
{
protected:
	int no;   // 编号
public:
	Shape& operator = (const Shape& s){no = s.no;}
	Shape(int no):no(no){}
	virtual ~Shape(){}

};

class Point
{
	int x;
	int y;
public:
	Point(int x, int y):x(x),y(y){};
	int GetX() const{return x;}
	int GetY() const{return y;}
};

class Polygon: public Shape
{
private:
	//Point* points;
	vector<Point*> points;
public:
	Polygon(const vector<Point*>& p, int no = 0);
	void Vector_clc();
	Polygon(const Polygon& polygon);
	Polygon& operator = (const Polygon& polygon);
	int getNo()const{return no;}
	const vector<Point*>& getPoints(){return points;}
	~Polygon();
};

// 构造函数
inline
Polygon::Polygon(const vector<Point*>& p, int no):Shape(no)
{
	if(!p.empty())
	{
		for(auto i = 0; i < p.size(); i++)
		{
			if(p[i]!=nullptr)
			{
				Point* point = new Point(*p[i]);
				points.push_back(point);
			}
		}
	}
}

// 拷贝构造函数
inline
Polygon::Polygon(const Polygon& polygon):Shape(polygon.no)
{
	vector<Point*>p(polygon.points);
	if(!p.empty())
	{
		for(auto i = 0; i < p.size(); i++)
		{
			if(p[i]!=nullptr)
			{
				Point* point = new Point(*p[i]);
				points.push_back(point);
			}
		}
	}
}

// 拷贝赋值函数
inline
Polygon& Polygon::operator = (const Polygon& polygon)
{
	if(&polygon == this)
		return *this;

	this->Shape::operator=(polygon);
	if(!points.empty())
	{
		this->Vector_clc();
	}
	vector<Point*>p(polygon.points);
	for(auto i = 0; i < p.size(); i++)
	{
		if(p[i]!=nullptr)
		{
			Point* point = new Point(*p[i]);
			this->points.push_back(point);
		}
	}
	return *this;
}

// 析构函数
inline
Polygon::~Polygon()
{
	Vector_clc();
}

inline
void Polygon::Vector_clc()
{
	for(auto i = 0; i < points.size(); i++)
	{
		delete points[i];
		points[i] = nullptr;
	}
	points.clear();
}


#endif