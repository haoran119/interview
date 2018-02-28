//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

void fx() {}
void fy() {}
void fz() {}

typedef void(*PFvv)();
PFvv functions[3] = {fx, fy, fz};

int main(int argc, char **argv)
{
    for (int i = 0; i < 3; i++ ) {
        /*****/
//        PFvv[i](); // Redefinition of 'i'
//        *functions[i](); // Indirection requires pointer operand ('void' invalid)
//        &functions[i](); // Cannot take the address of an rvalue of type 'void'
        functions[i]();
        functions[i];
    }

    return 0;
}
