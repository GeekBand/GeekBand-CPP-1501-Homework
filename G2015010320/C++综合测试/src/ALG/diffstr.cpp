// the entry point for Q2 -Total Difference Strings of algorithm final test

#include <iostream>
#include <set>
#include <string>

class __str_compare_q2 {
public:
  bool operator() (const std::string &s1, const std::string &s2) {
    const char *c1 = s1.c_str();
    const char *c2 = s2.c_str();

    if (s1.length() != s2.length()) {
      return true; // special case, just for q2's compare operator
    }

    const int LEN = s1.length();
    for (int i = 0, j = LEN - 1; i < LEN && j >= 0; ++i, --j) {
      if (c1[i] != c2[i] && c1[i] != c2[j]) {
        return true;
      }
    }
    return false;
  }
};

class TDS // TotalDiffString
{
public:
  static int count(const std::string str_arr[], int size) {
    std::set<std::string, __str_compare_q2> ss(str_arr, str_arr + size);
    return ss.size();
  }

private:
  TDS();
};

int main()
{
  const int N = 4;
  const std::string str_arr[] = { "abc", "cba", "abc", "Aaa" };
  int size = TDS::count(str_arr, N);
  std::cout << size << std::endl;

  return 0;
}