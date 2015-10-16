#include <iostream>
#include <set>
#include <string>
using namespace std;
struct Programmer{
	int Id;
	mutable wstring Name;
	Programmer(const int& id, const wstring& name): Id(id), Name(name){ }
	void Print() const{
		wcout << L"[" << Id << L"]:" << Name << endl;
	}
	
};

struct ProgrammerIdGreater{
	bool operator()(const Programmer& lhs, const Programmer &rhs) const{
		return lhs.Id > rhs.Id;
	}
};

struct ProgrammerNameComparer{
	bool operator()(const Programmer& lhs, const Programmer &rhs) const{
		return lhs.Name > rhs.Name;
	}
};
int main(int argc, char *argv[]) {
	set<Programmer, ProgrammerIdGreater> s;
	wstring Names[6] = {L"Scott Meyers", L"Martin Fowler", L"Bill Gates", L"P.J. Plaught", L"Stanley B. Lippman", L"Andrei Alexandrescu"};
	for(int i = 0; i < 6; ++i){
		s.insert(Programmer(i+1, Names[i]));
	}
	cout << "Initialize set1 according to Id comparater" << endl;
	for_each(s.begin(), s.end(), [](const Programmer &p){p.Print();});
	set<Programmer, ProgrammerIdGreater>::iterator search = s.find(Programmer(3, L"Bill Gates"));
	if(search != s.end()){
		(*search).Name = L"David Vandevoorde";
	}else{
		cout << "Not Found" << endl;
	}
	cout << "Find a programmer with id = 3, name = Bill Gates, and change the programmer's name" << endl;
	for_each(s.begin(), s.end(), [](const Programmer &p){p.Print();});
	set<Programmer, ProgrammerNameComparer> s2;
	for(int i = 0; i < 6; ++i){
		s2.insert(Programmer(i+1, Names[i]));
	}
	cout << "Initialize set1 according to Name comparater" << endl;
	for_each(s2.begin(), s2.end(), [](const Programmer &p){p.Print();});
}