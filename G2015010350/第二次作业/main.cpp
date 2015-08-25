#include "Rectangle.h"
using namespace std ;
int main(int argc, char const *argv[])
{
	Rectangle juxing1( 1 , 2 , 3 , 4 ) ;
	juxing1.info() ;
	cout << juxing1 << endl ;
	Rectangle juxing2( juxing1 ) ;
	std::cout << "Rectangle juxing2( juxing1 ) ;" << std::endl ;
 	cout << juxing2 << endl ;
 	Rectangle juxing3( 5, 6 , 7 , 8 ) ;
 	cout << juxing3 << endl ;
 	//赋值构造函数
 	juxing1 = juxing3 ;
 	std::cout << "juxing1 = juxing3 ;" << std::endl ;
 	cout << juxing1 << endl ;

 	Point p1( 12 ,12 ) ;
 	//利用符合
 	std::cout<< " 复合 " << std::endl ;
 	Rectangle juxing4( p1 , 12 ,12 ) ;
 	cout << juxing4 << endl ;
 	p1.setX( 10 ) ;
 	p1.setY( 10 ) ;
 	juxing4.info() ;
 	//利用委托
 	Point* p2 = new Point( 13 , 13 ) ;
 	std::cout<< " 委托 " << std::endl ;
 	Rectangle juxing5 ( p2 , 13 , 13 ) ;
 	cout << juxing5 << endl ;
 	p2->setX( 1 ) ;
 	p2->setY( 1 ) ;
 	juxing5.info() ;
 	std::cout << " 复合 ？ 委托 ？ " << std::endl ;
 	Rectangle juxing6 ( *p2 , 13 , 13 ) ;
 	cout << juxing6 << endl ;
 	p2->setX( 2 ) ;
 	p2->setY( 2 ) ;
 	juxing6.info() ;
 	Point*& p3 = p2 ;
 	p3->setX( 133 ) ;
 	p3->setY( 122 ) ;
 	p2->info() ;
 	std::cout << " Point p1 " << std::endl ;
 	p1.info() ;
 	std::cout << " Point &p4 " << std::endl ;
 	Point& p4 = p1 ;
 	p4 = *p2 ;
 	p4.info() ;
 	std::cout << " new Rectangle( 1 ,1 ,12 , 20 ) " << std::endl ;
 	Rectangle* _pJuxing7 = new Rectangle( 1 ,1 ,12 , 20 ) ;
 	_pJuxing7->info() ;
 	delete _pJuxing7 ;

 	std::cout << " new Rectangle( &p1 , 20 , 13 ) " << std::endl ;
 	Rectangle* _pJuxing8 = new Rectangle( p1 , 20 , 13 ) ;
 	_pJuxing8->info() ;
 	delete _pJuxing8 ;

 	std::cout<< " new Rectangle( p1 , 20 , 22 ) " << std::endl ;
 	Rectangle* _pJuxing9 = new Rectangle( &p1 , 20 , 22 ) ; 
 	_pJuxing9->info() ;

 	std::cout<< " Rectangle Juxing10( _pJuxing9 ) " << std::endl ;
 	Rectangle Juxing10( _pJuxing9 ) ;
 	Juxing10.info() ;

 	std::cout << " new Rectangle( _pJuxing9 ) " << std::endl ;
 	Rectangle* _pJuxing11 = new Rectangle( _pJuxing9 ) ;
 	cout << *_pJuxing11 << endl ;
 	_pJuxing11->setX( 2 ) ;
 	cout << *_pJuxing11 << endl ;
 	_pJuxing11->setY( 10) ;
 	cout << *_pJuxing11 << endl ;
 	delete _pJuxing11 ;

 	return 0;
}