//
//  MovingAverage.cpp
//  testproject
//
//  Created by Gutierrez on 15/10/17.
//  Copyright © 2015年 Gutierrez. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

class MovingAverage
{
public:
    MovingAverage(int period) : m_cycle(period) { }
    double next(double num) {
        m_sum += num;
        container.push_back(num);
        if (container.size() > m_cycle) {
            m_sum -= container.front();
            container.pop_front();
        }
        
        return m_sum / container.size();
    }
    
private:
    double m_sum = 0;
    int m_cycle;
    std::deque<double> container;
};

int main(){
    MovingAverage ma(2);
    std::cout << ma.next(1) << ", " << ma.next(3) << ", " << ma.next(4) << std::endl;
    return 0;
}
