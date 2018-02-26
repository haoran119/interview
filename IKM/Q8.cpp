//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class Gizmo{
    Gizmo();
    ~Gizmo();
    
    // declaration goes here
//    Gizmo(const Gizmo* copy_me) const; // 'const' qualifier is not allowed on a constructor
    
//    Gizmo(const Gizmo&) const; // 'const' qualifier is not allowed on a constructor
    
//    Gizmo(Gizmo& const copy_me); // 'const' qualifier may not be applied to a reference
    
    Gizmo(const Gizmo& v);
    
    Gizmo(const Gizmo&);
};

int main(int argc, char* argv[])
{
    return 0;
}
