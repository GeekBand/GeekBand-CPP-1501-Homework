#include "stdafx.h"
#include "Shape_hw2.h"
#include "ListClass.h"
#include <iostream>
class MainForm: public Form
{
public:
	MainForm(){}
	void addShape();
	List<Shape*> removeShape();
private:
	//Shape* pShape[20];
	List<Shape*> pShape;
};


void MainForm::addShape()
{
	 for(int k = 0; k < 10; k++)
	 {
		 Point p(rand()%10+1, rand()%10+1);
		 pShape.insertElement(new Rectangle(k, (int)(rand()%10+1), (int)(rand()%10+1), p));
	 }
	 for(int k = 10; k < 20; k++)
	 {
		 Point p(rand()%10+1, rand()%10+1);
		  pShape.insertElement(new Circle(k, (int)(rand()%10+1), p));
	 }
}

List<Shape*> MainForm::removeShape()
{
	MainForm::addShape();
	for(int k = 0; k < 20; k++)
	{
		if (pShape[k]->data->getArea()<50)
		{
			pShape.removeElement(pShape[k]);
		}
	}
	
	return pShape;
}