// stdafx.cpp : source file that includes just the standard includes
// homework2.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include <iostream>
#include "MainForm_hw2.h"
using namespace std;
// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
int _tmain(int argc, _TCHAR* argv[])
{
	MainForm m;
	m.addShape();
	//m.removeShape();
	List<Shape*> pShape = m.removeShape();
	
	cout<<"面积大于50的图形："<<endl;
	for(int k = 0; k< pShape.get_size(); k++)
	{
		cout<<k<<": "<<pShape[k]->data->getArea();
		cout<<"  "<<endl;
	 }
	 cout<<endl;
	 for(int k = pShape.get_size()-1; k>=0; k--)
	{
		delete pShape[k]->data;
		pShape[k]->data = nullptr;
		pShape.removeElement(pShape[k]);

	}
	system("pause");
	return 0;
}
