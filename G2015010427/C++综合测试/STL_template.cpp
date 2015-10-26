#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>

using namespace std;

// Q1:
void fun1() {
  vector<int> v1 = {0, 0, 30, 20, 0, 0, 0, 0, 10, 0};
  vector<int> v2;
  for (auto &i : v1) {
    not_equal_to<int> fun;
    if (fun(i, 0)) {
      v2.push_back(i);
    }
  }
  for (auto &i : v2) {
    cout << i << endl;
  }
}

//Q2:
struct Programmer {
  Programmer(const int id, const string& name) : 
  _id(id), _name(name) {}
  void Print() const {
    cout << "[" << _id << "]:" << _name << endl;
  }
  int _id;
  string _name;
};

struct ProgrammerIdGreater {
  bool operator()(const Programmer& l, 
                  const Programmer& r) const {
    return l._id > r._id;
  } 
};

struct ProgrammerNameComparer {
  bool operator()(const Programmer& l, 
                  const Programmer& r) const {
    return l._name > r._name;
  } 
};

void fun2() {
  set<Programmer, ProgrammerIdGreater> pset;  
  pset.insert(Programmer(1, "Scott Meyers"));
  pset.insert(Programmer(2, "Martin Fowler"));
  pset.insert(Programmer(3, "Bill Gates"));
  pset.insert(Programmer(4, "P.J. Plaught"));
  pset.insert(Programmer(5, "Stanley B.Lippman"));
  pset.insert(Programmer(6, "Andrei Alexandrescu"));
  for_each (pset.begin(), pset.end(), [] (const Programmer& p) {p.Print();});
  auto iter = pset.find(Programmer(3, "Bill Gates"));
  if (iter != pset.end()) {
    pset.erase(iter);
    pset.insert(Programmer(3, "David Vandevoorde"));
  } else {
    cout << "can not find";
  }
  for_each (pset.begin(), pset.end(), [] (const Programmer& p) {p.Print();});
  set<Programmer, ProgrammerNameComparer> pset2;  
  for (const auto &p : pset) {
    pset2.insert(p);
  }
  for_each (pset2.begin(), pset2.end(), [] (const Programmer& p) {p.Print();});
}

int main() {
  //fun1();
  fun2();
  return 0;
}
