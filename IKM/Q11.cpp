//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

int getLength() {
    return 10;
}

int size = getLength();
// char message[size]; // Variable length array declaration not allowed at file scope

int main(int argc, char* argv[])
{
    bool ok = true;
    
    if (!ok) {
        cout << "not ok" << endl;
    }

    const int size = 10;
    char message[size];

    int numerator, denominator;

    numerator = 10.0;
    denominator = 3.0;
    
    float quotient = numerator / denominator;

    // signed char scope is -128 ~ 127
    for (char idx = 0; idx < 250; idx ++) { // Comparison of constant 250 with expression of type 'char' is always true
        cout << "hello world" << endl;
    }

    return 0;
}
