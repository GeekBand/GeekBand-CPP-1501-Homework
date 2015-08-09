#ifndef _RECTANGLE_
#define _RECTANGLE_

class Shape{
  int no;
}

class Point{
  int x;
  int y;
public:
  Point(const Point &p):x(p.x),y(p.y){}
  Point()=default;
}

class Rectangle:public Shape{
private:
  int height;
  int width;
  Point *leftUp;
public:
  Rectangle(int _w = 0,int _h = 0,int _x = 0,int _y = 0):width(_w),height(_h),x(_x),y(_y){}
  Rectangle(const Rectangle &other):height(other.height),width(other.width),leftUp(new Point(other.leftUp)){}
  Rectangle & operator=(const Rectanle &other){
    if(other==this){
      return *this;
    }else{
      delete leftUp;
      leftUp=new Point(other);
      height=other.height;
      width=other.width;
      return *this;
    }
    ~Rectangle(){
      delete leftUp;
    }
    
  }
}


#endif
