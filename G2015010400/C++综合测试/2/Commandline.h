//
//  Commandline.h
//  testproject
//
//  Created by Gutierrez on 15/10/10.
//  Copyright © 2015年 Gutierrez. All rights reserved.
//

#ifndef Commandline_h
#define Commandline_h

#include "Iprogress.h"

class Commandline : public Iprogress
{
public:
    void doprogress(int old, int now){
        std::cout << "x:" << old << "->" << now << std::endl;
    }
private:
    
};

#endif /* Commandline_h */
