#pragma once

#include "stdafx.h"
#include "Shape_hw2.h"
#include "ListClass.h"
#include <iostream>
using namespace std;
//class MainForm: public Form
class MainForm
{
public:
	MainForm(){}
	void addShape();
	List<Shape*> removeShape();
	~MainForm();
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
	  for(int k = 0; k < 20; k++)
	  {
		  cout<<pShape[k]->data->getArea();
		  cout<<" ";
	  }
	  cout<<endl;
}

List<Shape*> MainForm::removeShape()
{
	int len = 20;
	for(int k = 0; k< pShape.get_size(); k++)
	{
		if (pShape[k]->data->getArea()<50)
		{
			delete pShape[k]->data;
			pShape[k]->data = nullptr;
			pShape.removeElement(pShape[k]);
			k--;
			len--;
		}
	}
	return pShape;
}

MainForm::~MainForm()
{
	//pShape.clear();
	/*
	 for(int k = 0; k< pShape.get_size();)
	{
		if(pShape[k]->data)
		{
			delete pShape[k]->data;
			pShape[k]->data = nullptr;
		}
		pShape.removeElement(pShape[k]);

	}*/
}