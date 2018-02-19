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
        
        int result = maxSubArrayHelpFunc(nums, 0, nums.size() - 1);
        
        return result;
    }
    
private:
    int maxSubArrayHelpFunc(vector<int>& nums, int left, int right) {
        // 叶子结点
        if (left == right) return nums.at(left);
        
        int middle = (left + right) / 2; // 中间节点
        int leftMax = maxSubArrayHelpFunc(nums, left, middle); // 左边最大连续子序列和
        int rightMax = maxSubArrayHelpFunc(nums, middle + 1, right); // 右边最大连续子序列和
        int preMax = nums.at(middle); // 包含中间节点的左边最大连续子序列和
        int sufMax = nums.at(middle + 1); // 包含中间节点的右边最大连续子序列和
        
        // 中间节点向左扩张
        int temp = 0;
        for (auto i = middle; i >= left; i --) {
            temp += nums.at(i);
            if (temp > preMax) preMax = temp;
        }
        
        // 中间节点向右扩张
        temp = 0;
        for (auto i = middle + 1; i <= right; i ++) {
            temp += nums.at(i);
            if (temp > sufMax) sufMax = temp;
        }
        
        // max { 左边最大连续子序列和，右边最大连续子序列和，包含中间节点的最大连续子序列和 }
        return max( max(leftMax, rightMax), preMax + sufMax);
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
