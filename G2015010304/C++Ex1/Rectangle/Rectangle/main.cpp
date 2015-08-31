#include<iostream>
#include"Rectangle.h"
using namespace std;

int main()
{

	while (true) {
		Rectangle a(0, 0, 0, 0);
		Rectangle b = a;
		Rectangle c = a;
		c = b;
	}
}