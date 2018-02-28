//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;

template<class T> using vec = std::vector<T>;
vec<float> incomes;

/*
typedef std::vector<T>  vec; // Use of undeclared identifier 'T'
vec<double> weights;
*/

typedef int intAlias;
intAlias count;

/*
typedef T genricAlias<T>; // Unknown type name 'T'
genricA1ias<int> population;
*/

template<typename T> using myGenric = T;
myGenric<int> age;

int main(int argc, char **argv)
{
}
