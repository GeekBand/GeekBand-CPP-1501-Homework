#include "Rectangle.h"
int main(){
	Rectangle r1(5, 3, 2, 2);
	Rectangle r2(r1);
	Rectangle r3(5, 4, 0, 0);
	r3 = r2;
	return 0;
}