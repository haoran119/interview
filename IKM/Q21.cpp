//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class base {
public:
    base() : code('B') { }
    char code;
};
    
class derived : public base
{
public:
    int code;
};

int main(void)
{
    derived d;
    d.code = 65;
    std::cout << d.code;
};
