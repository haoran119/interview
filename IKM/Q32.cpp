//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int rows = 10;
    int columns = 5;
    
    double **dArray = new double*[rows];
    
    for (int r = 0; r < rows; r ++) {
        /*****/
        
        // Assigning to 'double *' from incompatible type 'double **'; dereference with *
//        dArray[r] = new double*;
        dArray[r] = new double[columns];
        dArray[r] = new double;
        // Assigning to 'double' from incompatible type 'double *'; dereference with *
//        *dArray[r] = new double[columns];
        // Assigning to 'double *' from incompatible type 'double **'; dereference with *
//        dArray[r] = new double*[columns];
    }
}
