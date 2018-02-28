//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class BBus {
    int     DriverID;
    string  routeName;
    
    BBus(BBus &orig) {
        DriverID = orig.DriverID;
        routeName = orig.routeName;
    }
    
    BBus& operator=(BBus &rhs) {
        DriverID = rhs.DriverID;
        routeName = rhs.routeName;
        return *this;
    }

public:
    BBus(int id = 0, string rt = "") : DriverID(id), routeName(rt) {}
};

class C : public BBus {
public:
    void print() {
        cout << __func__ << endl;
    }
};

void testB(BBus objB) {
    cout << __func__ << endl;
}

/*
BBus testB2() {
    BBus objB;
    return objB; // Calling a private constructor of class 'BBus'
}
 */

int main(int argc, char **argv)
{
    BBus obj;

    BBus obj3;
    //    obj3 = obj; // 'operator=' is a private member of 'BBus'

    //    testB(obj); // Calling a private constructor of class 'BBus'

    //    BBus obj2(obj); // Calling a private constructor of class 'BBus'
    
    C objC;
    
    objC.print();
    
    return 0;
}
