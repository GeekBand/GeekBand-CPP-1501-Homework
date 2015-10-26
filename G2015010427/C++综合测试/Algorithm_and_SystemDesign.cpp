#include <set>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Q1
class MovingAverage {
 public:
  MovingAverage(int n) : n_(n), sum_(0) {}
  double next(double cnt) {
    sum_ += cnt;
    deq.push_back(cnt); 
    if (deq.size() > n_) {
      sum_ -= deq.front();
      deq.pop_front();
    }
    return sum_ / deq.size();
  }
 private:
  int n_;
  double sum_;
  deque<double> deq;
};
// end Q1

// Q2
string rev_string(const string& str) {
  string rev;
  for (auto iter = str.rbegin(); iter != str.rend(); ++iter) {
    rev.push_back(*iter);
  }
  return rev;
}

int TotalDifferent(const vector<string>& vec) {
  set<string> uniq(vec.begin(), vec.end());
  for (const auto &i : uniq) {
    string revs = rev_string(i);
    if (revs == i) {
      continue;
    }
    auto fp = uniq.find(revs);
    if (fp != uniq.end()) {
      uniq.erase(fp);
    }
  }
  return uniq.size();
} 
// end Q2


// Q3
struct Node {
  Node(char dat) : data(dat) {}
  char data;
  Node* left;
  Node* right;
};

Node* CreateTree() {
  char dat;
  scanf("%c", &dat);
  Node* p;
  if (dat == '#') {
    p = nullptr;
  } else {
    p = new Node(dat);
    p->left = CreateTree();
    p->right = CreateTree();
  }
  return p;
}

void PrintPath(vector<char>& vec) {
  cout << "[";
  for (size_t i = 0; i < vec.size() - 1; ++i) {
    cout << vec[i] << ",";
  }
  cout << vec[vec.size() - 1] << "]";
}

void PrintTree(Node* tree, vector<char> vec) {
  if (tree == nullptr) {
    return;
  }
  vec.push_back(tree->data);
  if (tree->left == nullptr && tree->right == nullptr) {
    PrintPath(vec);
  } {
    PrintTree(tree->left, vec);
    PrintTree(tree->right, vec);
  }
}
// end Q3

int main() {
  // Q1 UniTest
  MovingAverage ma(2);
  cout << (ma.next(1) == 1) << endl;
  cout << (ma.next(3) == 2) << endl;
  cout << (ma.next(4) == 3.5) << endl;
  // end Q1 UniTest

  // Q2 UniTest
  vector<string> vec1 = {"abc", "cba", "abc", "Aaa"};
  cout << (TotalDifferent(vec1) == 2) << endl;

  vector<string> vec2 = {"aba"};
  cout << (TotalDifferent(vec2) == 1) << endl;

  vector<string> vec3 = {"", ""};
  cout << (TotalDifferent(vec3) == 1) << endl;

  vector<string> vec4 = {"a", "", "a", "aa"};
  cout << (TotalDifferent(vec4) == 3) << endl;
  // end Q2 UniTest


  // Q3 UniTest
  Node* tree = CreateTree();
  vector<char> vec;
  PrintTree(tree, vec);
  // end Q3 UniTest
  return 0;
}


// Q4
//伪码
设计商品类
class Product {
  int id;
  string name;
  other_type opt_info;
};

//设计购物车类
class ShoppingCart {
  string user;
  list<Product> list;

  Add(Product p);
  Change(Product p);
  PrintOrder() return Order;
}

//设计订单类
class Order {
  ShoppingCart sc;
  int time;
  double pay;   
}

如果商品数量在1亿以上，对商品数据库进行分库分表存储。
对待处理的订单存储在redis中，等待后续处理。

抢购页面设计：
将用户的请求先装入到消息队列中，
之后由后续程序读取消息队列，
可以将消息队列的长度加以限制。
如果单个消息队列压力过大，可以使用多个队列，
但是消息要加入时间戳，以待后续归并消息。
// end Q4
