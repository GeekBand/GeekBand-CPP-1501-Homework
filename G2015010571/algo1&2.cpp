#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class MovingAverage{
	vector<int> v;
	int size;
public:
	MovingAverage(int size):size(size){ }
	double next(int input){
		v.push_back(input);
		int sum = 0, n = size, i = v.size() - 1;
		while(i >=0 && n > 0){
			sum += v[i];
			i--;
			n--;
		}
		return (double)sum/(v.size() < size? v.size():size);
	}
};

int totalDifferentStrings(vector<string> & v){
	if(v.size() == 0){
		return 0;
	}
	set<string> ss;
	for(int i = 0; i < v.size(); ++i){
		string temp = v[i];
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if(ss.find(temp) == ss.end()){
			reverse(temp.begin(), temp.end());
			if(ss.find(temp) == ss.end()){
				ss.insert(temp);
			}
		}
	}
	return ss.size();
}
int main(int argc, char *argv[]) {
	MovingAverage ma(2);
	cout << ma.next(1)<< endl;
	cout << ma.next(3)<< endl;
	cout << ma.next(4)<< endl;
	
	string strs[] = {"abc", "cba", "abc", "Aaa"};
	vector<string> v(begin(strs), end(strs));
	cout << totalDifferentStrings(v);
}