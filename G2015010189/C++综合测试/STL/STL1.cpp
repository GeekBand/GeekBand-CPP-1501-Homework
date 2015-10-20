#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename TElement>
struct printElement
{
	//printElement(ostream& out):os(out){}
	void operator()(const TElement& e)
	{
		cout<<e<<", ";
	}
	//ostream& os;
};

int main()
{
	int a[] = {0,0,30,20,0,0,0,0,10,0};
	vector<int> v1(a,a+10);
	vector<int> v2;
	//std::copy_if(v1.begin(),v1.end(),v2.begin(),(std::bind1st(std::not_equal_to<int>(),0)));
	vector<int>::iterator it1,it2 = v1.begin();
	int n = 0;
	while(it2!=v1.end())
	{
		it1 = find_if(it2,v1.end(),(std::bind1st(std::not_equal_to<int>(),0)));
		if(it1==v1.end())
		{
			break;
		}
		v2.push_back(*it1);
		it2 = it1+1;
	}
	cout<<v2.size()<<endl;
	std::for_each(v2.begin(),v2.end(),printElement<int>());
	system("pause");
	return 0;
}