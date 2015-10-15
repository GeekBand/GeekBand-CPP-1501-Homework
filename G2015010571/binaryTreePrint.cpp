#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val): val(val), left(NULL), right(NULL){ }
};

void dfs(TreeNode *root, vector<int>& temp, vector<vector<int> >& paths){
	temp.push_back(root->val);
	cout << root->val << endl;
	if(!root->left && !root->right){
		paths.push_back(temp);
		return;
	}
	if(root->left){
		dfs(root->left, temp, paths);
		temp.pop_back();
	}
	if(root->right){
		dfs(root->right, temp, paths);
		temp.pop_back();
	}
}
void printPath(TreeNode *root){
	if(root == NULL){
		return;
	}
	vector<vector<int> > paths;
	vector<int> temp;
	dfs(root, temp, paths);
	for(int i = 0; i < paths.size(); ++i){
		cout << "[";
		for(int j = 0; j < paths[i].size(); ++j){
			cout << paths[i][j];
			if(j != paths[i].size()-1){
				cout << ",";
			}
		}
		cout << "]" << endl;
	}
}

void dfs2(TreeNode *root, vector<pair<int, bool> >& temp, vector<vector<pair<int, bool> > >& paths, bool isLeft){
	temp.push_back(make_pair(root->val, isLeft));
	if(!root->left && !root->right){
		paths.push_back(temp);
		return;
	}
	if(root->left){
		dfs2(root->left, temp, paths, true);
		temp.pop_back();
	}
	if(root->right){
		dfs2(root->right, temp, paths, false);
		temp.pop_back();
	}
}
void printPathWithIndent(TreeNode *root){
	if(root == NULL){
		return;
	}
	vector<vector<pair<int, bool> > > paths;
	vector<pair<int, bool> > temp;
	dfs2(root, temp, paths, true);
	int width = 6;
	for(int i = 0; i < paths.size(); ++i){
		for(int j = 0; j < paths[i].size(); ++j){
			if(j == 0){
				cout << setw(6);
				width = 6;
			}else{
				if(paths[i][j].second){
					cout << setw(--width);
				}else{
					cout << setw(++width);
				}
			}
			cout << paths[i][j].first << endl;
		}
		if(i != paths.size() - 1){
			cout << setw(8) << "-----" << endl;
		}
	}
}
	
int main(int argc, char *argv[]) {
	TreeNode t1(3);
	TreeNode t2(1);
	TreeNode t3(2);
	TreeNode t4(5);
	TreeNode t5(6);
	TreeNode t6(8);
	TreeNode t7(7);
	t1.left = &t2;
	t1.right = &t4;
	t2.right = &t3;
	t4.left = &t5;
	t5.left = &t6;
	t4.right = &t7;
	printPathWithIndent(&t1);
}