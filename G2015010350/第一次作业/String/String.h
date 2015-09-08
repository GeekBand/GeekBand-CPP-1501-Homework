#ifndef _STRING_H_
#define _STRING_H_ 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class String
{
public:
	String(const char* cstr = 0 ) {
        if(cstr){
        	len = strlen( cstr ) ; 
        	m_date = new char[ len + 1 ];
        	strcpy_s( m_date , cstr ) ; 
        } else {
        	len = 0 ;
        	m_date = new char[1] ;
        	*m_date = '\0' ;
        }
	}
    String( const String& str ) {
    	m_date = new char[str.len + 1 ] ;
    	len = str.len ;
    	strcpy( m_date , str.m_date ) ;
    }
    String& operator=( const String& str) {
    	if( this == &str ) 
    		return *this ; 
    	
    	delete[] m_date ;
    	m_date = new char[str.len + 1] ;
    	len = str.len ;
    	strcpy( m_date , str.m_date ) ;
    	return *this ;
    }
	~String() {
        delete[] m_date ;
	}
	int& size() {
		return len ;
	}
	/* data */
private:
	char* m_date ;
	int len ;
};

#endif