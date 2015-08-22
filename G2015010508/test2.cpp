#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <stdio.h>
#include <math.h>

class Shape
{
   int no;
public:
   Shape( int no ) : no( no ) {}
   virtual ~Shape(){}
   int getNo( void ) const { return no; }
   virtual int getArea() const = 0;
};

class Point
{
   int x;
   int y;
public:
   Point( int x, int y ): x(x), y(y) {}
   Point( const Point& other )
   : x ( other.x ), y ( other.y )
   {
   }

   int getX( void ) const { return x; }
   int getY( void ) const { return y; }
};


class Circle: public Shape
{
   Point center;
   int radius;
public:
   Circle( int no, int radius, int x, int y )
   :Shape( no ),
    center( x, y ),
    radius( radius )
   {
   }

   virtual ~Circle()
   {
   }


//No need of copy constructor and copy assignment anymore, since now "center" 
//is a concrete object, complier will generate them.
   int getArea( void ) const { return ( this->radius * this->radius * M_PI ); }
};


class Rectangle: public Shape
{
   int width;
   int height;
   Point leftUp;
public:
   Rectangle( int no, int width, int height, int x, int y )
   :Shape( no ),
    width( width ),
    height( height ),
    leftUp( x, y )
   {
   }

   virtual ~Rectangle()
   {
   }

   int getArea( void ) const { return ( this->width * this->height ); }

   int getWidth( void ) const { return this->width; }
   int getHeight( void ) const { return this->height; }

   int getX( void ) const
   { 
      return leftUp.getX();
   }

   int getY( void ) const
   { 
      return leftUp.getY();
   }

//No need of copy constructor and copy assignment anymore, since now "center" 
//is a concrete object, complier will generate them.
};

void printRectange( const Rectangle& rec)
{
   std::cout << rec.getNo() << ":" << rec.getWidth() << "," <<  rec.getHeight() << "(" << rec.getX() << ","  << rec.getY() << ")\n";
}

int getRandomValue( void ) 
{
   return ( rand() % 10 + 1 );
}

Rectangle* Foo()
{
   Rectangle square(1, 10, 10, 3, 10);
   Rectangle* pSquare=&square;
   return pSquare;
}

int main()
{
   Shape* shapeArray[20] = {0};
   Shape* resultArray[20] = {0};
   int i = 0;

   std::cout << "Create rectange:\n";
   for ( ; i < 10; i++ )
   {
      shapeArray[i] = new Rectangle( i, 
                                     getRandomValue(), 
                                     getRandomValue(), 
                                     getRandomValue(),
                                     getRandomValue() );
      std::cout << shapeArray[i]->getNo() << ':' << shapeArray[i]->getArea() << '\n';
   }

   std::cout << "Create circle:\n";

   for ( ; i < 20; i++ )
   {
      shapeArray[i] = new Circle( i, 
                                     getRandomValue(), 
                                     getRandomValue(),
                                     getRandomValue() );
      std::cout << shapeArray[i]->getNo() << ':' << shapeArray[i]->getArea() << '\n';
   }

   int k = 0;
   for ( int j = 0; j < 20; j++ )
   {
      if ( NULL != shapeArray[j] )
      {
         if ( shapeArray[j]->getArea() >= 50 )
         {
            resultArray[k] = shapeArray[j];
            k++;
         }
      }
   }

   std::cout << "Large than 50 items:\n";
   while( k > 0 )
   {
      k--;
      std::cout << resultArray[k]->getNo() << ':' << resultArray[k]->getArea() << '\n';
      std::cout.flush();
   }
   

   for ( int i = 0; i < 20; i++ )
   {
      //release objects on HEAP
      delete shapeArray[i];
      //Here, do we need to delete resultArray[i] or can we?
      /*
      shapeArray[i] = NULL;
      if ( NULL != resultArray[i] )
      {
         std::cout << i << "is not empty";
         delete resultArray[i];
      }
      */
   }
   return 0;
}
   
