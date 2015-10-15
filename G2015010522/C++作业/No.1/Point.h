/*
 * Point.h
 *
 *  Created on: 2015年8月9日
 *      Author: Administrator
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	//Point(){};
	Point (int a=0,int b=0): x(a), y(b) {}

	~Point(){}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

private:
	int x;
	int y;
};

#endif /* POINT_H_ */
