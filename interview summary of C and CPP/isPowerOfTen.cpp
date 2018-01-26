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
    bool isPowerOfTen(int n)
    {
        if (n < 1)
            return false;
        
        while (n % 10 == 0) {
            n /= 10;
        }
        
        return n == 1;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    int result = 1;
    
    result = result && testSolution.isPowerOfTen(1);
    result = result && testSolution.isPowerOfTen(10);
    result = result && testSolution.isPowerOfTen(10000000);
    result = result && !testSolution.isPowerOfTen(0);
    result = result && !testSolution.isPowerOfTen(-1);
    result = result && !testSolution.isPowerOfTen(110);

    if (result)
        cout << "ALl tests pass!" << endl;
    
    return 0;
}
