// The entry point of Qustion 1 of STL

#include <vector>
#include <iostream>

// copy values of not equal to 'target' to the dest vector
template<typename T>
void not_equal_to(const std::vector<T> &src, std::vector<T> &dest, T target) {
  for (typename std::vector<T>::const_iterator it = std::begin(src); 
    it != std::end(src); ++it) {
    if (*it != target) {
      dest.push_back(*it);
	}
  }
}

template<typename T>
inline std::ostream & 
operator<< (std::ostream &os, const std::vector<T> &v) {
  os << "[ ";
  char dm[3] = { '\0', ' ', '\0' };
  for (typename std::vector<T>::const_iterator it = std::begin(v); 
    it != std::end(v); ++it) {
    std::cout << dm << *it;
    dm[0] = ',';
  }
  return os << " ]";
}

int main() {
  int arr[] = { 0, 0, 30, 20, 0, 0, 0, 0, 10, 0 };
  std::vector<int> v1;
  for (int i = 0; i < 10; ++i) {
    v1.push_back(arr[i]);
  }

  std::cout << v1 << std::endl;
  std::vector<int> v2;
  not_equal_to(v1, v2, 0);
  std::cout << v2 << std::endl;

  return 0;
}