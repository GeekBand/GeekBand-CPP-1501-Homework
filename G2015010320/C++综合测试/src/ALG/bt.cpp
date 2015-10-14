// the entry point for Q3 - Binary Tree Print of algorithm final test

#include <iostream>
#include <vector>

class Node 
{
public:
  int data_;
  Node *left_;
  Node *right_;
  Node(int data) :
    data_(data), left_(NULL), right_(NULL) 
  { }
};

inline std::ostream &
operator<< (std::ostream &os, Node *node) {
  return os << node->data_;
}

class BTree // Bianry tree
{
public:
  Node *root;
};

void init(BTree &tree) {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  Node *n7 = new Node(7);
  Node *n8 = new Node(8);
  
  n3->left_ = n1;
  n1->right_ = n2;
  n3->right_ = n5;
  n5->left_ = n6;
  n6->left_ = n8;
  n5->right_ = n7;
  tree.root = n3;
}

// helper of printing containers.
template<class Ch, class Tr, class Co>
std::basic_ostream<Ch, Tr>& operator<<(std::basic_ostream<Ch, Tr>& stream, Co& c) {
  stream << "{ ";
  std::copy(c.begin(), c.end(), std::ostream_iterator<typename Co::value_type>(stream, ", "));
  return stream << "}";
}

void __print_path(const std::vector<Node *> &path) {
  std::cout << path;
}

void __print_routs(Node *root, std::vector<Node *> &path) {
  if (root != NULL) {
    path.push_back(root);
    if (root->left_ == NULL && root->right_ == NULL) {
      __print_path(path);
      std::cout << "\n----------" << std::endl;
    } else {
      __print_routs(root->left_, path);
      __print_routs(root->right_, path);
    }
    path.pop_back();
  }
}

void printBtree(const BTree &tree) {
  std::vector<Node *> path;
  __print_routs(tree.root, path);
}

int main()
{
  BTree tree;
  init(tree);
  printBtree(tree);
  return 0;
}
