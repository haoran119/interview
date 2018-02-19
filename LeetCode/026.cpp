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
    // erase
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        for (auto i = 0; i < nums.size() - 1; i ++) {
            while (nums.at(i) == nums.at(i + 1) && i + 1 < nums.size()) {
                nums.erase(nums.begin() + i + 1);
            }
        }
        
        return nums.size();
    }

    // In-place algorithm
    int removeDuplicates1(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int  i = 0;
        
        for (int j = 1; j < nums.size(); j ++) {
            if (nums.at(j) != nums.at(i)) {
                ++ i;
                nums.at(i) = nums.at(j);
            }
        }
        
        return i + 1;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    vector<int>  sample {1,1,2};

    int size = testSolution.removeDuplicates1(sample);
    
    for (auto i = 0; i < size; i ++) {
        cout << sample.at(i) << endl;
    }
    
    return 0;
}
