//
//  total_difference_strings.cpp
//  testproject
//
//  Created by Gutierrez on 15/10/15.
//  Copyright © 2015年 Gutierrez. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

struct stringcompare
{
    bool operator() (const string& left, const string& right){
        if (left.size() != right.size())
            return true;
        for (int i = 0, j = left.size() - 1; i < left.size() && j >= 0; ++i, --j) {
            if (left[i] != right[i] && left[i] != right[j])
                return true;
        }
        return false;
    }
};

int main(){
    string s1;
    set<string, stringcompare> set1;
    while (cin >> s1) {
        set1.insert(s1);
    }
    //输出不同的个数
    cout << set1.size() << endl;
    return 0;
}