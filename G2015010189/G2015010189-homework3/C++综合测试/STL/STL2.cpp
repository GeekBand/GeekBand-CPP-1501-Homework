#include <string>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

struct Programmer
{
	Programmer(const int id, const std::wstring name):Id(id),Name(name)
	{}
	void Print() const
	{
		std::wcout << L"[" << Id << L"]:" << Name << std::endl;
	}
	int Id;
	std::wstring Name;
};

struct ProgrammerIdGreater:public std::binary_function<Programmer,Programmer,bool>
{
	const bool operator()(const Programmer& p1, const Programmer& p2) const
	{
		return (p1.Id > p2.Id)?true:false; 
	}
};

struct ProgrammerNameComparer:public std::binary_function<Programmer,Programmer,bool>
{
	const bool operator()(const Programmer& p1, const Programmer& p2) const
	{
		return (p1.Name < p2.Name)?true:false; 
	}
};

int main()
{
	const size_t nsize = 6;
	const Programmer programmer[nsize]={
		Programmer(1, L"Scott Meyers"),
		Programmer(2, L"Martin Fowler"),
		Programmer(3, L"Bill Gates"),
		Programmer(4, L"P.J.Plaught"),
		Programmer(5, L"Stanley B. Lippman"),
		Programmer(6, L"Andrei Alexandrescu")
	};
	// ��1������set1,��Id��������
	std::set<Programmer, ProgrammerIdGreater>set1(programmer,programmer+nsize);
	cout<<"��Id��������"<<endl;
	// ��2��for_each������ӡset1
	std::for_each(set1.begin(), set1.end(), mem_fun_ref(&Programmer::Print));

	// ��3������Id = 3, Name = "Bill Gates"�ļ�¼
	std::set<Programmer, ProgrammerIdGreater>::iterator it = set1.find(Programmer(3, L"Bill Gates"));
	// ��4���ҵ���¼����Name����ӡ
	if(it != set1.end())
	{
		//(*it).Print();
		cout<<endl;
		const_cast<Programmer&>(*it).Name = L"David Vandevoorde";
		std::for_each(set1.begin(), set1.end(), mem_fun_ref(&Programmer::Print));
		cout<<endl;
	}

	// ��5����6������set2,�������������򣬴�ӡ
	std::set<Programmer, ProgrammerNameComparer>set2(programmer,programmer+nsize);
	cout<<"��������������"<<endl;
	std::for_each(set2.begin(), set2.end(), mem_fun_ref(&Programmer::Print));

	system("pause");
	return 0;
}