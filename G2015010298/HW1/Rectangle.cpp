//  GeekBand G2015010298
//
//  Created by Xun Gong on 8/14/15.
//  Copyright (c) 2015 Xun Gong. All rights reserved.
//

#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Rectangle* r1 = new Rectangle(4, 5, 0, 1, 0);
    cout << "Width: "<< r1->w() << ", Height: " << r1->h() <<  ", LeftUp: (" << r1->getleftup()->xVal() << ", "<< r1->getleftup()->yVal() << "), LeftUp Address: " << r1->getleftup() << endl;
    
    Rectangle r2(-10, 3, 7, 9, 1);
    cout << "Width: "<< r2.w() << ", Height: " << r2.h() <<  ", LeftUp: (" << r2.getleftup()->xVal() << ", "<< r2.getleftup()->yVal() << "), LeftUp Address: " << r2.getleftup() << endl;
    
    r2 = *r1;
    
    Rectangle r3(r2);
    cout << "Width: "<< r3.w() << ", Height: " << r3.h() <<  ", LeftUp: (" << r3.getleftup()->xVal() << ", "<< r3.getleftup()->yVal() << "), LeftUp Address: " << r3.getleftup() << endl;
    
    Rectangle r4 = *r1;
    cout << "Width: "<< r4.w() << ", Height: " << r4.h() <<  ", LeftUp: (" << r4.getleftup()->xVal() << ", "<< r4.getleftup()->yVal() << "), LeftUp Address: " << r4.getleftup() << endl;
    

    
    return 0;
}
