#ifndef _COMPLEX_H_
#define _COMPLEX_H_ 
#include <iostream>
using namespace std ;
class complex
{
public:
	complex( const double real = 0 , const double imag = 0 ): rl(real) , ig(imag) { } 
	~complex() { }
	complex( const complex& x) 
	{
		rl = x.rl ;
		ig = x.ig ;
	}
	complex& operator = ( const complex& x )
	{
		this->rl = x.rl ;
		this->ig = x.ig ;
		return *this ;
	}
	complex& operator = ( const double x ) 
	{
		this->rl += x ;
		return *this ;
	}
	complex& operator += ( const complex& x)
	{
		this->rl += x.rl ;
		this->ig += x.ig ;
		return *this ;
	}
	complex& operator += ( const double x)
	{
		this->rl += x ;
		return *this ;
	}
	
	double real ( )  const
	{
		return rl ;
	}
	double imag ( ) const
	{
		return ig ;
	}
	
private:
	double rl , ig ;
	/* data */
};
inline complex operator + ( const complex& x , const complex& y)
{
	return complex( x.real() + y.real() , x.imag() + y.imag() ) ;
}
inline complex operator + ( const complex& x , const double& y)
{
	return complex( x.real() + y , x.imag() ) ;
}
inline complex operator + ( const double& x , const complex& y)
{
	return complex( x  + y.real() , y.imag() ) ;
}
inline ostream& operator<< ( ostream& os , const complex& x ) 
{
	return os << '(' << x.real() << ',' << x.imag() << ')' ;
}
// inline basic_ostream<charT,traits>&  operator<< (basic_ostream<charT,traits>& ostr, const complex& rhs)
// {
// 	return ostr << '(' << rhs.real() << ',' << rhs.imag() << ')' ; 
// }

inline const bool operator == (  const complex& x , const  complex& y ) 
{
	return x.real() == y.real() && x.imag() == y.imag() ;
}
inline const bool operator == ( const complex& x , const double y ) 
{
	return x.real() == y ;
}
inline const bool operator == (  const double x , const  complex& y ) 
{
	return x == y.real() ;
}
inline const bool operator != ( const complex& x , const complex& y ) 
{
	return  ! (x == y) ;
}
inline const bool operator != ( const complex& x , const double y ) 
{
	return  ! (x == y) ;
}
inline const bool operator != ( const double x , const complex& y ) 
{
	return  ! (x == y) ;
}
#endif