//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // empty array
        if (nums.empty()) return 0;
        
        int result = nums.at(0), f = 0;
        
        for (auto i = 0; i < nums.size(); i ++) {
            // f[i] = max{ a[i], f[i - 1] + a[i] }
            f = max(f + nums.at(i), nums.at(i));

            // target = max { f[i] }
            result = max(result, f);
        }
        
        return result;
    }
};

int main ()
{
    Solution testSolution;
    
    vector< vector<int> > vecTest{ {-2, 5, 3, -6, 4, -8, 6}, {}, {1, 2, 3, 4, 5} };
    
    for (auto v : vecTest)
        cout << testSolution.maxSubArray(v) << endl;
    
    return 0;
}
