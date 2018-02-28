//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class MyArray {
public:
    // declaration goes here
    int& operator()(int);
//    int& operator[int](int);    // Expected ']'
//    int& operator[int]();       // Expected ']'
//    int& operator(int)();       // Expected ')'
    int& operator[](int);
};

int main(int argc, char* argv[])
{
    return 0;
}
