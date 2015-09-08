#include "complex.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	complex c1( 1 , 2 ) ;
	complex c2( 2 , 5 ) ; 
	complex c3( c1 + c2 ) ;
	std::cout << c3.real() << std::endl ;
	std::cout << c3.imag() << std::endl ;
	complex c4( c1 + 2 ) ;
	complex c5( 2  + c2) ;
	complex c = c5 ;
	complex c6 = c5 ;
	std::cout << " cout << c " << std::endl ;
	std::cout << c << std::endl ;
	if ( c6 == c )
	{
		/* code */
		std::cout << "yes" << std::endl ;
	}
	complex c7(3) ;
	if (c7 == 3)
	{
		std::cout << "yes " << std::endl ;
	}
	if (3== c7)
	{
		std::cout << " yes " << std::endl ;
	}

	if ( c6 != c )
	{
		;
	}
	else
	{
		std::cout << "no" << std::endl ;
	}

	if (c7 != 3)
	{
 		;
	}
	else
	{
		std::cout << "no " << std::endl ;
	}

	if ( 3 != c7)
	{
		;
	}
	else
	{
		std::cout << " no " << std::endl ;
	}

	
	return 0;
}