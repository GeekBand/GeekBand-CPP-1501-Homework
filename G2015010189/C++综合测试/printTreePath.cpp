#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
void  ConnectTreeNodes(TreeNode* root, TreeNode* left, TreeNode* right)
{
	root->left = left;
	root->right = right;
}
void printTreePath(TreeNode* node, vector<int>& NodesList, vector<bool>& LeftOrRight, int& row);
void printTreePath(TreeNode* node)
{
	if(node == nullptr)
	{
		cout<<"null!"<<endl;
		return;
	}
	vector<int>NodesList;
	vector<bool>LeftOrRight;
	int row = 1;  // 遍历到达的节点所在层数
	printTreePath(node, NodesList, LeftOrRight,row);
	
}
void printTreePath(TreeNode* node, vector<int>& NodesList, vector<bool>& LeftOrRight, int& row)
{
	if(node == nullptr) return;
	row++;
	NodesList.push_back(node->val);
	// 到达叶子节点
	if((node->left == nullptr)&&(node->right == nullptr))
	{
		int lastSpace = row + 3;
		for(int k = 0; k < lastSpace; k++)
			cout<<" ";
		cout<<NodesList[0]<<endl;
		for(int i = 1; i <  NodesList.size(); i++)
		{
			if(LeftOrRight[i-1])
			{
				lastSpace--;
				for(int k = 0; k < lastSpace; k++)
					cout<<" ";
				cout<<NodesList[i]<<endl;
			}
			else
			{
				lastSpace++;
				for(int k = 0; k < lastSpace; k++)
					cout<<" ";
				cout<<NodesList[i]<<endl;
			}
		}
		cout<<"-----------------------"<<endl;
	}
	if(node->left != nullptr)
	{
		LeftOrRight.push_back(true);
		printTreePath(node->left, NodesList, LeftOrRight, row);
	}
	if(node->right != nullptr)
	{
		LeftOrRight.push_back(false);
		printTreePath(node->right, NodesList, LeftOrRight, row);
	}
	NodesList.pop_back();
	LeftOrRight.pop_back();
	row--;
}

//             3
//         /      \
//        1        5
//         \       /\
//          2     6  7
//               /
//              8

//   [3 1 2],[3 5 6 8], [3 5 7]
void test1()
{
	TreeNode* t1 = new TreeNode(3);
	TreeNode* t2 = new TreeNode(1);
	TreeNode* t3 = new TreeNode(5);
	TreeNode* t4 = new TreeNode(2);
	TreeNode* t5 = new TreeNode(6);
	TreeNode* t6 = new TreeNode(7);
	TreeNode* t7 = new TreeNode(8);

	ConnectTreeNodes(t1,t2,t3);
	ConnectTreeNodes(t2,nullptr,t4);
	ConnectTreeNodes(t3,t5,t6);
	ConnectTreeNodes(t5,t7,nullptr);
	cout<<"-----------------------"<<endl;
	cout<<"test1:"<<endl;
	printTreePath(t1);
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
	delete t7;
}

//            3
//           /      
//          1        
//         /       
//        5     
//       /
//      2
//     /
//    6
//   /
//  7
//   [3 1 5 2 6 7]
void test2()
{
	TreeNode* t1 = new TreeNode(3);
	TreeNode* t2 = new TreeNode(1);
	TreeNode* t3 = new TreeNode(5);
	TreeNode* t4 = new TreeNode(2);
	TreeNode* t5 = new TreeNode(6);
	TreeNode* t6 = new TreeNode(7);

	ConnectTreeNodes(t1,t2,nullptr);
	ConnectTreeNodes(t2,t3,nullptr);
	ConnectTreeNodes(t3,t4,nullptr);
	ConnectTreeNodes(t4,t5,nullptr);
	ConnectTreeNodes(t5,t6,nullptr);
	cout<<"-----------------------"<<endl;
	cout<<"test2:"<<endl;
	printTreePath(t1);
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
}

//  3
//   \      
//    1        
//     \      
//      5     
//       \
//        2
//         \
//          6

//   [3 1 5 2 6]
void test3()
{
	TreeNode* t1 = new TreeNode(3);
	TreeNode* t2 = new TreeNode(1);
	TreeNode* t3 = new TreeNode(5);
	TreeNode* t4 = new TreeNode(2);
	TreeNode* t5 = new TreeNode(6);

	ConnectTreeNodes(t1,nullptr,t2);
	ConnectTreeNodes(t2,nullptr,t3);
	ConnectTreeNodes(t3,nullptr,t4);
	ConnectTreeNodes(t4,nullptr,t5);
	cout<<"-----------------------"<<endl;
	cout<<"test3:"<<endl;
	printTreePath(t1);
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
}

void test4()
{
	TreeNode* t1= new TreeNode(5);
	cout<<"-----------------------"<<endl;
	cout<<"test4:"<<endl;
	printTreePath(t1);
	delete t1;
	// 5
}
void test5()
{
	cout<<"-----------------------"<<endl;
	cout<<"test5:"<<endl;
	printTreePath(nullptr);
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	system("pause");
	return 0;
}