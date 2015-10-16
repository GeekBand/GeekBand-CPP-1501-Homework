#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(int argc, char *argv[]) {
	int A[] = {0,0,30,20,0,0,0,0,10,0};
	vector<int> v1(begin(A), end(A));
	vector<int> v2;
	copy_if(v1.begin(), v1.end(), back_inserter(v2), bind2nd(not_equal_to<int>(), 0));
	for(int i = 0; i < v2.size(); ++i){
		cout << v2[i] << endl;
	}
}