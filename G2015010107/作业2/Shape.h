#ifndef _Shape_
#define _Shape_
class Shape{
private: 
	int no;
public:
	virtual int getArea()const=0;
	
	virtual ~Shape(){};	
}; 
#endif
