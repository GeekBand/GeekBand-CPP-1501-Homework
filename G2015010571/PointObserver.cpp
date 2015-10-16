#include <iostream>
#include <vector>

using namespace std;
class Observer;
class Point{
	int x;
	int y;
	vector<Observer *> list;
public:
	Point(int x = 0, int y = 0): x(x), y(y){}
	void attach(Observer *obs){
		list.push_back(obs);
	}
	void changeX(int newx){
		x = newx;
		notify();
	}
	void changeY(int newy){
		y = newy;
		notify();
	}
	int getX() const {return x;}
	int getY() const {return y;}
	void notify() const;
};

class Observer{
	Point *pt;
public:
	Observer(Point *p):pt(p){
		pt->attach(this);
	}
	void getPointStatus() const{
		cout <<  "Point has been changed to (" << pt->getX() << "," << pt->getY() << ")" << endl;
	}
	virtual void update(){
		getPointStatus();
	}
};

class ClientType: public Observer{
	int someClientData;
public:
	ClientType(Point *p, int anydata): Observer(p), someClientData(anydata){ }
	void update(){
		Observer::update();
		someClientProcess();
	}
	void someClientProcess(){ }
};
void Point::notify() const{
	for(int i = 0; i < list.size(); ++i){
		list[i]->update();
	}
}
int main(int argc, char *argv[]) {
	Point p(6,4);
	ClientType ob(&p, 5);
	p.changeX(5);
	p.changeY(9);
}