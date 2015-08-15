#include <iostream>
#include <assert.h>

class Shape
{
   int no;
   public:
   Shape( int no ) : no( no ) {}
   int getNo( void ) const { return no; }
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


class Rectangle: public Shape
{
   int width;
   int height;
   Point* leftUp;

public:
   Rectangle( int no, int width, int height, int x, int y )
   :Shape( no ),
    width( width ),
    height( height )
   {
      this->leftUp = new Point( x, y );
   }

   ~Rectangle()
   {
      delete leftUp;
      leftUp = NULL;
   }

   int getWidth( void ) const { return this->width; }
   int getHeight( void ) const { return this->height; }

   int getX( void ) const
   { 
      if ( leftUp != NULL)
      {
         return leftUp->getX();
      }
      else
      {
         assert( "something wrong!" );

         return 0;
      }
   }

   int getY( void ) const
   { 
      if ( leftUp != NULL)
      {
         return leftUp->getY();
      }
      else
      {
         assert( "something wrong!" );
         return 0;
      }
   }

Rectangle( const Rectangle& other )
   : Shape(other),
     height(other.height),
     width(other.width)
   {
      if ( other.leftUp != NULL )
      {
         (*this->leftUp) (*(other.leftUp) ); 
      }
      else
      {
         this->leftUp = NULL;
      }
   }

   Rectangle& operator=(const Rectangle &other )
   {
      if ( this == &other )
      {
         return *this;
      }

      this->Shape::operator=(other);
      this->width = other.width;
      this->height = other.height;

      if( other.leftUp != NULL )
      {
         if( this->leftUp != NULL )
         {
            (*leftUp ) = *(other.leftUp);
         }
         else
         {
            leftUp = new Point(*other.leftUp);
         }
      }
      else
      {
         delete this->leftUp;
         this->leftUp = NULL;
      }

      return *this;
   }
};

void printRectange( const Rectangle& rec)
{
   std::cout << rec.getNo() << ":" << rec.getWidth() << "," <<  rec.getHeight() << "(" << rec.getX() << ","  << rec.getY() << ")\n";
}


Rectangle* Foo()
{
   Rectangle square(1, 10, 10, 3, 10);
   Rectangle* pSquare=&square;
   return pSquare;
}

int main()
{
   Rectangle square1( 1,  100, 100, 3, 4 );
   printRectange( square1 );

   Rectangle square2( 2,  50, 50, 0, 4 );
   printRectange( square2 );

   Rectangle square3( square1 );
   printRectange( square3 );

   square1 = square2;
   printRectange( square1 );

   Rectangle* pFoo = Foo();
   printRectange( *pFoo );

   return 0;
}
   
