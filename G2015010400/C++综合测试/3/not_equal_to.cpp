//
//  not_equal_to.cpp
//  testproject
//
//  Created by Gutierrez on 15/10/12.
//  Copyright © 2015年 Gutierrez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v1{0, 0, 30, 20, 0, 0, 0, 0, 10, 0};
    not_equal_to<int> f;
    typename not_equal_to<int>::first_argument_type element(0);
    vector<int> v2;
    
    auto it = find_if(v1.begin(), v1.end(), binder1st<not_equal_to<int>>(f, element));
    while (it != v1.end()) {
        v2.push_back(*it);
        it = find_if(it + 1, v1.end(), binder1st<not_equal_to<int>>(f, element));
    }
    
    for (auto &c : v2) cout << c << " ";
    cout << endl;
    
    return 0;
}