//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class A {
public:
    int age;
    int weight;
protected:
    int iq;
};

class B : protected A {
public:
    using A::iq;
    using A::age;
};

class C : private B {
public:
    using B::iq;
    using B::weight;
};

int main()
{
    B   bObj;
    C   cObj;
    
    /*****/
    
    bObj.iq = 190;
    cObj.iq = 190;
//    bObj.weight = 110; // Cannot cast 'B' to its protected base class 'A'
    bObj.age = 20;
    cObj.weight = 110;
    
    return 0;
}
