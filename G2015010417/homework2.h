#ifndef Shape_h
#define Shape_h
class Shape{
	int no;
public:
	virtual int getArea()=0;
};
class Point{
public:
	Point(){}
	Point(int a,int b):x(a),y(b){}
private:
	int x;
	int y;
};
class Rectangle:public Shape{
public:
	Rectangle(int wid,int hei,int x,int y):width(wid),height(hei),leftUp(new Point(x,y)){}
	Rectangle(const Rectangle &other){
		this->width=other.width;
		this->height=other.height;
		leftUp=new Point();
		*leftUp=*other.leftUp;
	}
	Rectangle& operator=(const Rectangle& rhs){
		if(this==&rhs)
			return *this;
		delete leftUp;
		leftUp=new Point();
		*leftUp=*rhs.leftUp;
		return *this;
	}
	~Rectangle(){
		delete leftUp;
	}
	virtual int getArea(){
		return width*height;
	}	   
private:
	int width;
	int height;
	Point* leftUp;
};
class Circle:public Shape{
public:
	Circle(int a,int b,int r):Center(new Point(a,b)),radius(r){}
	Circle(const Circle& other){
		this->radius=other.radius;
		Center=new Point();
		*Center=*other.Center;
	}
	Circle& operator=(const Circle& rhs){
		if(this==&rhs)
			return *this;
		this->radius=rhs.radius;

		delete Center;
		Center=new Point();
		*Center=*rhs.Center;
	}
	~Circle(){
		delete Center;
	}
	int getArea(){
		return static_cast<int>(3.14*radius*radius);
	}
	Point *Center;
	int radius;
};
#endif
