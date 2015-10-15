// tesy.cpp : ¶¨Òå¿ØÖÆÌ¨Ó¦ÓÃ³ÌÐòµÄÈë¿Úµã¡£
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include"homework2.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

		Shape * s[20];
		int count;
		for(int i=0;i<10;i++){
			int tmp1,tmp2,tmp3,tmp4;
			while(!(tmp1=rand()%10));
			while(!(tmp2=rand()%10));
			while(!(tmp3=rand()%10));
			while(!(tmp4=rand()%10));
			s[i]=new Rectangle(tmp1,tmp2,tmp3,tmp4);
		}
		for(int j=10;j<20;j++){
			int tmp1,tmp2,tmp3;
			while(!(tmp1=rand()%10));
			while(!(tmp2=rand()%10));
			while(!(tmp3=rand()%10));
			s[j]=new Circle(tmp1,tmp2,tmp3);
		}
		Shape *result[20];
		for(int i=0,j=0;i<20;i++){
			if(s[i]->getArea()>=50){
				result[j]=s[i];
				j++;
			}
			count=j;
		}
		for(int i=0;i<count;i++){
			cout<<result[i]->getArea()<<endl;
		}

	return 0;
}

