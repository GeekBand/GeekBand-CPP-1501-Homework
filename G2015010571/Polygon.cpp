#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>
#include <unordered_map>

using namespace std;
class Shape{
	int no;
public:
	Shape(int id = 0): no(id){}	
	virtual ~Shape(){}
};

class Point{
	int x;
	int y;
public:
	Point(int x, int y): x(x), y(y){}
	int getx() const{ return x; }
	int gety() const{ return y; }
};

class Polygon : public Shape{
	shared_ptr<Point> head;
	vector<shared_ptr<Point> > v;
public:
	Polygon(int x, int y):head(new Point(x, y)){
		v.push_back(head);
	}
	Polygon(const Polygon & other): Shape(other){
		if(other.head.get() != NULL){
			Point * temp = other.head.get();
			head = std::make_shared<Point>(temp->getx(), temp->gety());
			v = other.v;
		}else{
			throw invalid_argument("Shape should have at least one point");
		}
	}
	Polygon &operator=(const Polygon &other){
		if(this == &other){
			return *this;
		}
		Shape::operator=(other);
		if(other.head.get() != NULL){
			Point * temp = other.head.get();
			head = std::make_shared<Point>(temp->getx(), temp->gety());
			v = other.v;
		}else{
			throw invalid_argument("Shape should have at least one point");
		}
		return *this;
	}
	void addPoint(int x, int y){
		for(int i = 0; i < v.size(); ++i){
			if(v[i]->getx() == x && v[i]->gety() == y){
				throw invalid_argument("This point has already in the polygon");
			}
		}
		shared_ptr<Point> sp(new Point(x, y));
		v.push_back(sp);
	}
	void deletePoint(int x, int y){
		for(int i = 0; i < v.size(); ++i){
			if(v[i]->getx() == x && v[i]->gety() == y){
				v.erase(v.begin() + i);
				return;
			}
		}
		throw invalid_argument("This point is not in the polygon");
	}
	void printAll(){
		for(int i = 0; i < v.size(); ++i){
			cout << "(" << v[i]->getx() << "," << v[i]->gety() << ")" << endl;
		}
	}
};
