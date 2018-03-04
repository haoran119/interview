//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class Box {
    double  volume;
public:
    Box()   {};
    Box(double v) : volume(v)   {};
    
    bool operator==(Box &rhs) {
        return this->volume == rhs.volume;
    }
    
    bool operator==(double v) {
        Box rhs(v);
        return volume == rhs.volume;
    }
    /*
     bool operator==(Box &rhs, double v) { // Overloaded 'operator==' must be a binary operator (has 3 parameters)
     Box temp(v);
     return rhs.volume == temp.volume;
     }
     */
    friend bool cmp(double v, Box &rhs); // must declared w/ the parameter nameb98
};

bool cmp(double v, Box &rhs) {
    Box temp(v);
    return rhs.volume == temp.volume;
}

int main(int argc, char **argv)
{
    Box box1, box2(8.75);
    
    if (box1 == 7.25)   // comparison 1
        cout << 1 << endl;
    
    if (box1 == box2)   // comparison 2
        cout << 2 << endl;

/*
    // Invalid operands to binary expression ('double' and 'Box')
    if (8.75 == box2)   // comparison 3
        cout << 3 << endl;;
*/
    
    if (cmp(8.75, box2))
        cout << 3 << endl;
    
    return 0;
}
