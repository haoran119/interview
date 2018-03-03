//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

enum REG {stocks, bonds};
enum LTC {swaps, swaptions};
enum DRV {futures, options};

REG team1;
LTC team2;
DRV team3;

int main(int argc, char **argv)
{
    //    team2 = 1;
    //    team1 = stocks + 1;
    //    team3 = options + futures;
    
    team1 = bonds;
    
    //    team1 = futures;
    
    return 0;
}
