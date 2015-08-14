/*
 * Test.cpp
 *
 *  Created on: 2015年8月9日
 *      Author: Administrator
 */
#include "Rectangle.h"
int main(int argc, char **argv) {
	Rectangle r1(11,12,13,14);
	Rectangle *r2 = new Rectangle(22,23,24,25);
	Rectangle &r3 = r1;
	Rectangle r4 = *r2;
	r4 = r3;
	r3 = r1;
}



