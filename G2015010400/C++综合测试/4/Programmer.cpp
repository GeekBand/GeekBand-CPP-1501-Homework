//
//  Programmer.cpp
//  testproject
//
//  Created by Gutierrez on 15/10/14.
//  Copyright © 2015年 Gutierrez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

struct Programmer
{
    Programmer(const int id, const wstring name): m_id(id), m_name(name) {}
    void Print() const
    {
        wcout << L"[" << m_id << L"]:" << m_name << endl;
    }
    int m_id;
    wstring m_name;
};
struct ProgrammerIdGreater : public binary_function<Programmer, Programmer, bool>
{
    bool operator() (const Programmer& left, const Programmer& right)
    {
        return (left.m_id > right.m_id);
    }
};
struct ProgrammerNameComparer :public binary_function<Programmer, Programmer, bool>
{
  bool operator() (const Programmer& left, const Programmer& right)
    {
        return (left.m_name < right.m_name);
    }
};
int main(){
    set<Programmer, ProgrammerIdGreater> set1;
    set1.insert(Programmer(1, L"Scott Meyers"));
    set1.insert(Programmer(6, L"Andrei Alexandrescu"));
    set1.insert(Programmer(2, L"Martin Fowler"));
    set1.insert(Programmer(3, L"Bill Gates"));
    set1.insert(Programmer(4, L"P.J. Plaught"));
    set1.insert(Programmer(5, L"Stanley B. Lippman"));
    
    for_each(set1.begin(), set1.end(), mem_fun_ref(&Programmer::Print));
    
    auto it = set1.find(Programmer(3, L"Bill Gates"));
    if (it != set1.end() ) {
        const_cast<Programmer&>(*it).m_name = L"David Vandevoorde";
    }
    for_each(set1.begin(), set1.end(), mem_fun_ref(&Programmer::Print));
    
    set<Programmer, ProgrammerNameComparer> set2;
    set2.insert(Programmer(1, L"Scott Meyers"));
    set2.insert(Programmer(6, L"Andrei Alexandrescu"));
    set2.insert(Programmer(2, L"Martin Fowler"));
    set2.insert(Programmer(3, L"Bill Gates"));
    set2.insert(Programmer(4, L"P.J. Plaught"));
    set2.insert(Programmer(5, L"Stanley B. Lippman"));
    
    for_each(set2.begin(), set2.end(), mem_fun_ref(&Programmer::Print));
    
    return 0;
}