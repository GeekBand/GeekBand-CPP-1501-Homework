#include "Rectangle.h"
using namespace std;

int main()
{
	Rectangle* pRec;
	Rectangle rect(105,210,77,93);

	pRec = new Rectangle(15,20,125,250);

	cout<<"pRec->showInfo()"<<endl;
	pRec->showInfo();
	
	cout<<"rect.showInfo()"<<endl;
	rect.showInfo();
	
	Rectangle rect_cpy(rect);
	cout<<"rect_cpy.showInfo()"<<endl;
	rect_cpy.showInfo();

	rect_cpy = *pRec;
	cout<<"After rect_cpy = *pRec"<<endl;
	rect_cpy.showInfo();

	delete pRec;
	return 0;
}
