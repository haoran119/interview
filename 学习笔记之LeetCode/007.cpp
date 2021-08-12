//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int sign = 1;
        
        if (x < 0) {
            sign = -1;
            x = abs(x);
        }
        
        while (x != 0) {
            if (result > (INT_MAX - x % 10) / 10) // it's ok coz input would not be reverse of INT_MIN
                return 0;

            result = result * 10 + x % 10;
            x /= 10;
        }
        
        return result * sign;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    string      result;
    
    vector<int> iVec = {123, -123, 120, 2147483647, -2147483648, 0};
    
    /*
     321
     -321
     21
     0
     0
     0
     */
    for (auto i : iVec) {
        cout << testSolution.reverse(i) << endl;
    }

    return 0;
}
