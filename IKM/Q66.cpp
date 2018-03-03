//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

int main ()
{
    enum DAY { Mon = 11, Tue = 12 };
    
    enum DAY var = Mon;
    DAY var = DAY::Mon;
//    enum DAY var = dynamic_cast<enum DAY>(Mon); // 'enum DAY' is not a reference or pointer
    enum DAY var = DAY::Mon;
//    enum DAY var = DAY.Mon; // 'DAY' does not refer to a value

    return 0;
}
