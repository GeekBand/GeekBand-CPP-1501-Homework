#include <deque>
#include <iostream>
using namespace std;

class MovingAverage {
	int size;
	deque<double> num;
public:
	MovingAverage(double s):size(s){}
    double next(double n)
	{
		if(size == 0) return 0;
		double av = 0;
		if(num.size()>=size)
		{
			num.pop_front();
		}
		num.push_back(n);
		for(int i = 0; i < num.size(); i++)
		{
			av += num[i];
		}
		av/=num.size();
		return av;
	}
};


void test1()
{
	MovingAverage m(2);
	double testdata[] = {1,3,4};
	double result1[] = {1,2,3.5};
	bool flag=true;
	cout<<"test1:size = 2, move to 1, 3, 4"<<endl;
	for(int i = 0; i < 3; i++)
	{
		if(m.next(testdata[i])!=result1[i]) 
			flag = false;
	}
	if(flag)
		cout<<"test1:right!"<<endl;
	else
		cout<<"test1:wrong!"<<endl;		
}
void test2()
{
	MovingAverage m(0);
	double testdata[] = {1,2,3.5};
	bool flag=true;
	cout<<"test2:size = 0, move to 1, 2, 3.5"<<endl;
	for(int i = 0; i < 3; i++)
	{
		if(m.next(testdata[i])>0) flag = false;
	}
	if(flag)
		cout<<"test2:right!"<<endl;
	else
		cout<<"test2:wrong!"<<endl;		
}
void test3()
{
	MovingAverage m(6);
	double testdata[] = {1,3,41,20,53,8,7,9,23,44,5,32,1,21,29};
	double result1[] = {1,2,15,16.25,23.6,21,22,23,20,24,16,20,19,21,22};
	bool flag=true;
	cout<<"test3:size = 6, move to 1,3,41,20,53,6,4,11,21,13,60,32,33,13,10"<<endl;
	for(int i = 0; i < 15; i++)
	{
		double n = m.next(testdata[i]);
		//cout<<n<<";  ";
		if(n!=result1[i]) 
			flag = false;
	}
	if(flag)
		cout<<"test3:right!"<<endl;
	else
		cout<<"test3:wrong!"<<endl;		
}
int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}