//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class SomeClass {
protected:
    int data;
    friend class AnotherClass;
};

void SomeFunc(SomeClass sc) {
    sc.data = 5; // 'data' is a protected member of 'SomeClass'
}

class AnotherClass {
public:
    void Another(SomeClass sc) {
        sc.data = 25;
    }
    
    friend void SomeFunc(SomeClass sc);
};

int main(int argc, char **argv)
{
    SomeClass sc;
    SomeFunc(sc);
    
    cout << sc.data << endl; // 'data' is a protected member of 'SomeClass'

    return 0;
}
