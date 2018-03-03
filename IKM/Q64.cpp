//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class MyClass {
    double scores[100];
public:
    double avg () { return 0; }
    double high() { return 0; }
    double low () { return 0; }
};

int main(int argc, char **argv)
{
/*
    double (MyClass::*f)();
    f = &MyClass::avg;
*/
    
    double (MyClass::*f)() = &MyClass::avg;
    
    return 0;
}
