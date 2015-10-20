//
//  BinaryTreePrint.cpp
//  testproject
//
//  Created by Gutierrez on 15/10/17.
//  Copyright © 2015年 Gutierrez. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct BTNode
{
    int m_value;
    BTNode *m_left;
    BTNode *m_right;
    BTNode(int x) : m_value(x), m_left(NULL), m_right(NULL) {}
};
struct BTree // Bianry tree
{
    BTNode *root;
};

// void CreatBTree(BTNode *&root)

void init(BTree &tree) {
    BTNode *n1 = new BTNode(1);
    BTNode *n2 = new BTNode(2);
    BTNode *n3 = new BTNode(3);
    BTNode *n5 = new BTNode(5);
    BTNode *n6 = new BTNode(6);
    BTNode *n7 = new BTNode(7);
    BTNode *n8 = new BTNode(8);
    
    n3->m_left = n1;
    n1->m_right = n2;
    n3->m_right = n5;
    n5->m_left = n6;
    n6->m_left = n8;
    n5->m_right = n7;
    tree.root = n3;
}

//输出路径(递归)
void FindAllPath(BTNode *pRoot, vector<int> path)
{
    if (pRoot != NULL)
    {
        path.push_back(pRoot->m_value);
        if (pRoot->m_left == NULL && pRoot->m_right == NULL)
        {
            cout << "[";
            for (vector<int>::iterator iter = path.begin(); iter != path.end(); iter++)
            {
                if (iter + 1 == path.end()) {
                    cout << *iter;
                }else{
                    cout << *iter << ",";
                }
                
            }
            cout << "],";
            
        }
        else
        {
            FindAllPath(pRoot->m_left, path);
            FindAllPath(pRoot->m_right, path);
        }
    }
}

int main()
{
    vector<int> path;
    BTree tree;
    init(tree);
    FindAllPath(tree.root, path);
    return 0;
}