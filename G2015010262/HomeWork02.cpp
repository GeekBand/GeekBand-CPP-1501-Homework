#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;

int totalnum = -999;

class Shape{
private:
  int no;
public:
  Shape (int _no ) :no ( _no) {}
  virtual double getArea () = 0;
  virtual void getParameters ( ) = 0;
  virtual ~Shape (){};
};

class Point{
private:
  int x;
  int y;
public:
  Point (int _x=0,int _y=0):x(_x),y(_y) {}
};

class Rectangle:public Shape
{
private:
  int width;
  int height;
  Point leftUp;
public:
  Rectangle ( int _w = 0, int _h = 0, int _x = 0, int _y = 0, int _no = 0 ) :width ( _w ), height ( _h ), leftUp ( _x, _y ), Shape (_no)  {  }
  double getArea ( ) {
    return this->width*this->height;
  }
  void getParameters () { cout << "width:" << width << " height:" << height; }
};

class Circle :public Shape
{
private:
  Point center;
  int radius;
public:
  Circle ( int _r = 0, int _x = 0, int _y = 0, int _no = 0 ) :radius ( _r ), center ( _x, _y ), Shape ( _no )  {  }
  double getArea ( ) {
    return (double) 3.1415926*this->radius*this->radius;
  }
  void getParameters ( ) { cout << "radius:" << radius; }
};

Shape** helper ( int num )
{
  Shape **pShape = new Shape*[num];
  int *index = new int[num];
  int count = 0;
  srand ( (unsigned)time ( NULL ) );

  for (int i = 0; i < num; i++)
  {
    index[i] = 0;
    if (i < num / 2)
    {
      pShape[i] = new Rectangle ( rand ( ) % 10 + 1, rand ( ) % 10 + 1, rand ( ) % 10 + 1, rand ( ) % 10 + 1, i );
    }
    else
    {
      pShape[i] = new Circle ( rand ( ) % 10 + 1, rand ( ) % 10 + 1, rand ( ) % 10 + 1, i );
    }

    pShape[i]->getParameters ();
    cout << " => " << pShape[i]->getArea () << endl;

    if (pShape[i]->getArea () >= 50)
    {
      index[i] = 1;
      count++;
    }
  }

  totalnum = count;
  Shape **pShapeFinal = new Shape*[count];
  count = 0;
  for (int i = 0; i < num; i++)
  {
    if (index[i] == 1)
    {
      pShapeFinal[count++] = pShape[i];
    }
  }

  delete[] pShape;
  pShape = nullptr;

  return pShapeFinal;
}

int main ()
{
  int num = 20;  
  
  Shape** results = helper ( num );    

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  for (int i = 0; i < totalnum; ++i)
  {
    cout << results[i]->getArea ( ) << endl;
  }  

  delete[] results;
  results = nullptr;

  return 0;
}
