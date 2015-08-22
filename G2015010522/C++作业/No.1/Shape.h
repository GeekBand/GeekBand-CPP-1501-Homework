/*
 * Shape.h
 *
 *  Created on: 2015年8月9日
 *      Author: Administrator
 */

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
public:
	Shape():no(index){
		index++;
	};
	~Shape() {
	}
	int getNo() const {
		return no;
	}

	;
private:
	static int index;
	int no;

};
int Shape::index = 0;

#endif /* SHAPE_H_ */
