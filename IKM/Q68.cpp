//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

template<class T1, class T2>
// RETURN-TYPE-HERE myfunc(const T1 &lhs, const T2 &rhs) {return lhs + rhs;}
// auto myfunc (const T1 &lhs, const T2 &rhs) {return lhs + rhs;} // 'auto' return without trailing return type; deduced return types are a C++14 extension

// decltype(lhs + rhs) myfunc (const T1 &lhs, const T2 &rhs) {return lhs + rhs;} // Use of undeclared identifier 'rhs'

auto myfunc(const T1 &lhs, const T2 &rhs)->decltype(lhs+rhs) {return lhs + rhs;}

int main ()
{
    return 0;
}
