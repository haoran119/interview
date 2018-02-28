//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

typedef int MYVAR1;
MYVAR1 m1;

// alias MYVAR4 long; // Unknown type name 'alias'

using MYVAR2 = char;
MYVAR2 m2;

// type MYVAR3 double; // Unknown type name 'type'

// typedef MYVAR5 using int; // Unknown type name 'MYVAR5'

int main(int argc, char **argv)
{
    m2 = 'a';

    return 0;
}
