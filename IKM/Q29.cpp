//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

double f1(int i);
double f2(int i);
double f3(int i);
double f4(int i);
double f5(int i);

/*
double processor(int i, double(*f), int idx);
double processor(int i, double(*f(int)), int idx);
double processor(int i, double(*f)(int), int idx);
double processor(int i, double(*f[]), int idx);
double processor(int i, double(f[])(), int idx);
*/

//double processor(int i, double(*f), int idx) { return 0;}
//double processor(int i, double(*f(int)), int idx) { return 0;}
//double processor(int i, double(*f)(int), int idx) { return 0;}
//double processor(int i, double(*f[]), int idx) { return 0;}
//double processor(int i, double(f[])(), int idx) { return 0;}


int main(int argc, char **argv)
{
    double  results[5];
    typedef double(*pfdi)(int);
    pfdi    funcs[5] = {f1, f2, f3, f4, f5};
    
//    int dataPoint = getDataPoint();
    int dataPoint = 0;
    
    for (int i = 0; i < 5; i ++) {
        results[i] = processor(dataPoint, funcs, i);
    }
}
