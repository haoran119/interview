//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    for (double d = 1.0; d <= 1.9; d += 0.1)
        cout << "testA" << endl;
    
    for (int i = 15; i; i --)
        cout << "testB" << endl;
    
//    for (true) // Expected ';' in 'for' statement specifier
        cout << "testC" << endl;
    
    for (; ;)
        cout << "testD" << endl;
    
//    for (int i = 0, i < 10, i ++) // Redefinition of 'i'
        cout << "testE" << endl;

    return 0;
}
