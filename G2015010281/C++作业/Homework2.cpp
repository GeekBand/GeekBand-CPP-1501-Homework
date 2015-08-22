#include <math>
#include <iostream>

using namespace std;

class Shape
{
	int no;
public:
	virtual int getArea() = 0;
	virtual void print(){}
};

class Point
{
	int x;
	int y;
};

class Rectangle: public Shape
{
	int width;
	int height;

	Point leftUp;

public:
	Rectangle(){}
	Rectangle(int);
	~Rectangle(){}
	void print();
};

class Circle: public Shape
{	
	Point center;
	int radius;

public:
	Circle(){}
	Circle(int);
	~Circle(){}
	void print();
};

//返回1~10之间的随机数
inline
int getRandNumber()
{
  srand(time(NULL));
	int res = rand() % 10;
	return res == 0 ? 10 : res;
}

Rectangle::Rectangle(int number): no(number)
{

}

void Rectangle::print()
{
	cout << "Rectangle instance: no = " << no
		<< ", width = " << width
		<< ", height = " << height
		<< ", leftUp.x = " << leftUp.x
		<< ", leftUp.y = " << leftUp.y
		<< ", square = " << width * height;
}

//随机赋值属性，返回面积
int Rectangle::getArea()
{
	width = getRandNumber();
	height = getRandNumber();

	leftUp.x = getRandNumber();
	leftUp.y = getRandNumber();

	return width * height;
}

Circle::Circle(int number): no(number)
{

}

void Circle::print()
{
	cout << "Circle instance: no = " << no
		<< ", radius = " << radius
		<< ", center.x = " << center.x
		<< ", center.y = " << center.y
		<< ", square = " << PI * radius * radius;
}

//随机赋值属性，返回面积
int Circle::getArea()
{
	radius = getRandNumber();

	center.x = getRandNumber();
	center.y = getRandNumber();

	return PI * radius * radius;
}

Shape** randShapes(int& count)
{
	//初始化长度为20的数组，类型为Shape类型，存储两种图形的指针
	Shape* shapeArr[20];

	int i = 1;
	int arr_index = 0;
	for (; i <= 10; ++i)
	{
		Shape* shape = new Rectangle(i);
		if (shape->getArea() < 50)
		{
			delete shape;
		}
		else
		{
			shapeArr[arr_index] = shape;
			++arr_index;
		}
	}

	for (; i <= 20; ++i)
	{
		Shape* shape = new Circle(i);
		if (shape->getArea() < 50)
		{
			delete shape;
		}
		else
		{
			shapeArr[arr_index] = shape;
			++arr_index;
		}
	}

	Shape** res = new (Shape*)[arr_index];
	for (int i = 0; i < arr_index; ++i)
	{
		res[i] = shapeArr[i];
	}

	count = arr_index;

	return res;

	
}

int main(int argc, char const *argv[])
{
	int count = 0
	Shape** shapes = randShapes(count);

	for (int i = 0; i < count; ++i)
	{
		//print
		if (typeid(*(shapes[i])) == typeid(Rectangle))
	    {
	         Rectangle *shape = dynamic_cast<Rectangle*>(shapes[i]);
	         shape->print();
	    }

		if (typeid(*(shapes[i])) == typeid(Circle))
	    {
	         Circle *shape = dynamic_cast<Circle*>(shapes[i]);
	         shape->print();
	    }
	}

	for (int i = 0; i < count; ++i)
	{
		delete shapes[i];
	}
	delete[] shapes;

	return 0;
}
