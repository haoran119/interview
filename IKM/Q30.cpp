//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
#include <typeinfo> // std::typeid
using namespace std;

int somFunc() { return 10; }

int main(int argc, char **argv)
{
    auto a1 = 5;
    auto a2 = somFunc();
    
    decltype(a2)    d4;
    decltype(somFunc()) d5 = 5;
    
    double a3 = 4.0;
    auto &a6 = a3;
    
    cout << typeid(a1).name() << endl;
    cout << typeid(a2).name() << endl;
    cout << typeid(d4).name() << endl;
    cout << typeid(d5).name() << endl;
    cout << typeid(a3).name() << endl;
    cout << typeid(a6).name() << endl;
}
