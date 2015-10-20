//
//  main.cpp
//  testproject
//
//  Created by Gutierrez on 15/10/10.
//  Copyright © 2015年 Gutierrez. All rights reserved.
//

#include <iostream>

#include "Point.h"
#include "Iprogress.h"
#include "Commandline.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Point p1(1,1);
    Point p2(3,2);
    Commandline command;
    p1.setObserver(&command);
    p1.setx(2);
    p1.sety(2);
    p1 = p2;
    
    
    
    
    return 0;
}
