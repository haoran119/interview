//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

int b = 1;

int x() { b ++; return b; }
int y() { b *= 3; return b - 1; }
int z() { b = b + 8; return b + 2; }

int main(int argc, char **argv)
{
    int a = x() - y() + z(); // 2 - 5 + 16
    
    // 13
    cout << a << endl;
    
    // 14
    cout << b << endl;

    return 0;
}
