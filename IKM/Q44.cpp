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

template <typename T>
void processCollection(T t) {
    // Static_assert failed "collection is empty"
    static_assert(std::is_empty<T>::value, "collection is empty"); // Line 1
    
    // ...
};

int main(int argc, char **argv)
{
    std::vector<int>    ages;
    
    // ...
    
    processCollection<std::vector<int>>(ages);  // Line 2

    return 0;
}
