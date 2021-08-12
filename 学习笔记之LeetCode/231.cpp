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
    bool isPowerOfTwo(int n)
    {
        return ((n > 0) && ((n & (n - 1)) == 0));
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    auto nums = {0, 1, 2, 3, 4, 8, 16, 1000, 1024};
    
    for (auto num : nums)
    {
        cout << num << " isPowerOfTwo ? " << testSolution.isPowerOfTwo(num) << endl;
    }
    
    return 0;
}
