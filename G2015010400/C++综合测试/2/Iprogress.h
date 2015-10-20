//
//  Iprogress.h
//  testproject
//
//  Created by Gutierrez on 15/10/10.
//  Copyright © 2015年 Gutierrez. All rights reserved.
//

#ifndef Iprogress_h
#define Iprogress_h

class Iprogress
{
public:
    virtual void doprogress(int old, int now) = 0;
    virtual ~Iprogress() {}
};

#endif /* Iprogress_h */
