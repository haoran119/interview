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
    int Fibonacci(const int& n)
    {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else {
            int t, f0 = 0, f1 = 1;
            
            for (int i = 2; i < n + 1; i ++)
            {
                t = f1;
                f1 = f0 + f1;
                f0 = t;
            }
            
            return f1;
        }
    }
    
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    for (auto i = 0; i < 10; i ++)
        cout << testSolution.Fibonacci(i) << endl;
    
    return 0;
}
