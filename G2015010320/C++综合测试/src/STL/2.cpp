// The entry point of Question 2 of STL

#include <set>
#include <iostream>
#include <string>
#include <cassert>

// define an Programmer
class Programmer
{
private:
  const int id_;
  std::string name_;

public:
  explicit Programmer(const int &id, const std::string &name)
    : id_(id), name_(name) { }

  int id() const { return id_; }
  std::string name() const { return name_; }
  void setName(std::string name) {
    name_ = name;
  }

public:
  virtual ~Programmer() { }
};

// provides the sorted and unique 
// capacity for container of `Programmer`
// with id in desc order
class ProgrammerIdGreater
{
public:
  bool operator()(const Programmer *p1, const Programmer *p2) const {
    assert(p1 != NULL && p2 != NULL);
    return (p1->id() - p2->id()) > 0;
  }
};

// provides the sorted and unique 
// capacity for container of `Programmer`
// with name in asc order
class ProgrammerNameLess
{
public:
  bool operator()(const Programmer *p1, const Programmer *p2) const {
    assert(p1 != NULL && p2 != NULL);
    return std::strcmp(p1->name().c_str(), p2->name().c_str()) < 0;
  }
};

class PrintForEach
{
public:
  void operator()(const Programmer *p) {
    assert(p != NULL);
    std::cout << p << ", ";
  }
};

class deleteForEach
{
public:
  void operator()(const Programmer *p) {
    assert(p != NULL);
    delete p;
  }
};

// helper of printing Programmer
inline std::ostream &
operator<< (std::ostream &os, const Programmer *p) {
  return os << "[" << p->id() << "]: " << p->name();
}

// helper of printing containers.
template<class Ch, class Tr, class Co>
std::basic_ostream<Ch, Tr>& operator<<(std::basic_ostream<Ch, Tr>& stream, Co& c) {
  stream << "{ ";
  std::copy(c.begin(), c.end(), std::ostream_iterator<typename Co::key_type>(stream, ", "));
  return stream << "}";
}

inline void
initArr(const Programmer *ps[]) {
  ps[0] = new Programmer(1, "Scott Meyers");
  ps[1] = new Programmer(2, "Martin Fowler");
  ps[2] = new Programmer(3, "Bill Gates");
  ps[3] = new Programmer(4, "P.J. Plaught");
  ps[4] = new Programmer(4, "Stanley B. Lippman"); // emulate id conflicts
  ps[5] = new Programmer(6, "Andrei Alexandrescu");
}

// It's a demostraction, you should not use this to delete anything
inline void
cleanSet(const std::set<const Programmer *, ProgrammerIdGreater>& c) {
  std::for_each(c.begin(), c.end(), deleteForEach());
}

inline void
cleanArr(const Programmer *ps[], int size) {
  const int N = size;
  for (int i = 0; i < N; ++i) {
    if (ps[i] != NULL) delete ps[i];
  }
}

int main() {
  const int N = 6;
  const Programmer *ps[N] = { NULL };
  initArr(ps);
  
  std::set<const Programmer *, ProgrammerIdGreater> p_set_A(ps, ps + N);
  std::cout << "Origin set A: " << p_set_A << std::endl;
  // find the Programmer with id = 3
  {
    std::auto_ptr<Programmer> target(new Programmer(3, "David Vandevoorde"));
    std::set<const Programmer *, ProgrammerIdGreater>::iterator found = 
      p_set_A.find(target.get());
    if (found != std::end(p_set_A)) { // found it and modify then
      // this const cast is necessary, since we need to change the name here
      const_cast<Programmer *>(*found)->setName(target->name());
    }
  }
  std::cout << "Modified set A: " << p_set_A << std::endl;

  std::set<const Programmer *, ProgrammerNameLess> p_set_B(ps, ps + N);
  std::cout << "Modified set B: " << p_set_B << std::endl;

  cleanArr(ps, N);
  return 0;
}
