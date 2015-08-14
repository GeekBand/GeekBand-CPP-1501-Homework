#include "Rectangle.h"
 
void main(void)
{
	Rectangle r = new Rectangle(1 ,1 ,2, 2);
	Rectangle *r_p = new Rectangle(1 ,1 ,2, 2);

	Rectangle r_1(1 ,1 ,2, 2);
	Rectangle r_2(r_1);
	Rectangle r_3 = r_2;
}