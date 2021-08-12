//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n < 1) {
            return false;
        }
        
        while (n % 3 == 0) {
            n /= 3;
        }
        
        return n == 1;
    }

    bool isPowerOfThree2(int n)
    {
        return n > 0 && 1162261467 % n == 0;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    auto nums = {0, 1, 2, 3, 4, 6, 9, 27, 1162261467};
    
    for (auto num : nums)
    {
        cout << num << " isPowerOfThree ? " << testSolution.isPowerOfThree(num) << endl;
        cout << num << " isPowerOfThree2 ? " << testSolution.isPowerOfThree2(num) << endl;
    }
    
    return 0;
}
