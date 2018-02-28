//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class Vector {
public:
    constexpr Vector( double i, double j, double k ) // Line 1
    : ivec( i ), jvec( j ), kvec( k )
    {}
    
    constexpr Vector( const Vector &rhs )   // Line 2
    : ivec( rhs.ivec ), jvec( rhs.jvec ), kvec( rhs.kvec )
    {}
    
private:
    double ivec, jvec, kvec; // Line 3
};

int main(int argc, char **argv)
{
    Vector vec1( 2, 7, -1 ); // Line 4
//    constexpr Vector vec2( vec1 ); // Line 5
    Vector vec2( vec1 ); // Line 5

    return 0;
}
