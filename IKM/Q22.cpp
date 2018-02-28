//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <utility>      // std::move
#include <algorithm>    // std::copy_if, std::for_each
using namespace std;

int main()
{
    std::vector<int> sequence{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    
    /*****/
    
    // 1 2 3 4 5 6 7 8 9 10 11 12
//    iota( sequence.begin(), sequence.end(), 1 );

    // 0 1 1 0 1 5 8 13 21 34 55 89
//    move( sequence.begin(), sequence.begin() + 2, sequence.begin() + 3 );

    // 0 1 1 1 1 1 1 1 1 1 1 1
//    for_each( sequence.begin(), sequence.end(),
//             []( int& elem ) { if ( elem > 1 ) elem = 1; } );

    // 0 1 1 0 1 5 8 13 21 34 55 89
//    copy_if( sequence.begin (), sequence.begin() + 2, sequence.begin() + 3,
//            []( int elem ) { return elem <= 1; } );

    // 0 1 2 3 4 5 6 7 8 9 10 11
    iota( ++sequence.begin(), sequence.end(), 1 );

    // Print out the modified sequence -- what will it be?
    for( int elem : sequence )
    {
        std::cout << elem << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}
