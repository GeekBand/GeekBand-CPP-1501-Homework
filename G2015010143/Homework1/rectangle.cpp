#include <iostream>
#include "rectangle.h"

int main()
{
    std::cout << "Geekband C++ Homework:" << std::endl;

    Rectangle r1(100,200,5,5);

    std::cout << r1.disp_no() <<std::endl;
    std::cout << r1.disp_width() <<std::endl;
    std::cout << r1.disp_height() <<std::endl;
    std::cout << r1.disp_leftUp_x() <<std::endl;
    std::cout << r1.disp_leftUp_y() <<std::endl;
 
    Rectangle r2(r1);

    std::cout << r2.disp_no() <<std::endl;
    std::cout << r2.disp_width() <<std::endl;
    std::cout << r2.disp_height() <<std::endl;
    std::cout << r2.disp_leftUp_x() <<std::endl;
    std::cout << r2.disp_leftUp_y() <<std::endl;
    
    Rectangle r3(400,400,10,10); 

    std::cout << r3.disp_no() <<std::endl;
    std::cout << r3.disp_width() <<std::endl;
    std::cout << r3.disp_height() <<std::endl;
    std::cout << r3.disp_leftUp_x() <<std::endl;
    std::cout << r3.disp_leftUp_y() <<std::endl;

    r3 = r1;

    std::cout << r3.disp_no() <<std::endl;
    std::cout << r3.disp_width() <<std::endl;
    std::cout << r3.disp_height() <<std::endl;
    std::cout << r3.disp_leftUp_x() <<std::endl;
    std::cout << r3.disp_leftUp_y() <<std::endl;
  
}
