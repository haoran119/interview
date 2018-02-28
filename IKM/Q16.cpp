//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class x {
    x& operator< (const x& rhs) const {
        int thisVol = height * width * length;
        int thatVol = rhs.height * rhs.width * rhs.length;
        
        // Non-const lvalue reference to type 'x' cannot bind to a temporary of type 'bool'
        return thisVol < thatVol;
    }
/*
    bool operator< (const x& rhs) const {
        int thisVol = height * width * length;
        int thatVol = rhs.height * rhs.width * rhs.length;
        
        return thisVol < thatVol;
    }
*/
private:
    int height;
    int length;
    int width;
};

int main(int argc, char* argv[])
{
    return 0;
}
