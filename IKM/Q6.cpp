//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

template <typename T, int duration>
double power (double amplitude, int frequency = 1000) { return amplitude * frequency; }

int main(int argc, char* argv[])
{
    double output;

    output = power<int, 100>(3.0, 'a');
//    output = power<500>(3.0); // No matching function for call to 'power'
    output = power<int, 500>(3.0, 100);
//    output = power<int>(3.0, 100); // No matching function for call to 'power'
//    output = power<int, char>(3.0); // No matching function for call to 'power'
    output = power<int, 500>(3.0);

    cout << output << endl;
    
    return 0;
}
