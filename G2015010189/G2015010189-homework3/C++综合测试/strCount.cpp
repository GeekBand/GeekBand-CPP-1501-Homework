#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int strCount(vector<string>& strin)
{
	int cnt=0;
	if(strin.size()==0)return cnt;
	vector<string>strList;
	string s1;
	for(int i = 0; i < strin.size(); i++)
	{
		s1=strin[i];
		reverse(s1.begin(),s1.end());
		if(s1 >= strin[i])
			strList.push_back(s1);
		else 
			strList.push_back(strin[i]);
	}
	sort(strList.begin(),strList.end());
	vector<string>::iterator itor = strList.begin();
	s1="";
	while(itor != strList.end())
	{
		if(*(itor)!=s1)
		{
			s1 = *itor;
			cnt++;
		}
		++itor;
	}
	return cnt;
}

void test1()
{
	vector<string>s;
	if (strCount(s)==0)
		cout<<"test1: right!"<<endl;
	else
		cout<<"test1: wrong!"<<endl;
}
void test2()
{
	vector<string>s;
	s.push_back("abc");
	s.push_back("cba");
	s.push_back("abc");
	s.push_back("Aaa");
	s.push_back("abcdef");

	if (strCount(s)==3)
		cout<<"test2: right!"<<endl;
	else
		cout<<"test2: wrong!"<<endl;
}
void test3()
{
	vector<string>s;
	s.push_back("lkjhgl");
	s.push_back("lghjkl");
	s.push_back("ghjkl");
	s.push_back("lgl");
	s.push_back("kjhg");

	int result = strCount(s);
	if (result==4)
		cout<<"test3: right!"<<endl;
	else
		cout<<"test3: wrong!"<<endl;
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}