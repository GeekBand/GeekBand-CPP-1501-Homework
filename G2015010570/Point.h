#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	Point(int x, int y);
	virtual ~Point();
	void setX(int x);
	int getX() const;
	void setY(int y);
	int getY() const;
private:
	int x;
	int y;
};

#endif
