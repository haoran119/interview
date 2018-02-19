//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    // STL sort
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // STL sort in ascending order
        return nums.at(nums.size() - k);
    }
    
    // Divide and Conquer
    int findKthLargest2(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        
        while (true) {
            int pos = partition(nums, l, r); // one time quick sort
            
            if (pos == k - 1) // the k-th largest key
                return nums.at(k - 1);
            else if (pos < k - 1) // in the right partition of pos
                l = pos + 1;
            else // in the left partition of pos
                r = pos - 1;
        }
    }
    
    int partition(vector<int> & nums, int left, int right) {
        int i = left, j = right, pivot = nums.at(left); // pivot key
        
        while (i < j) {
            while (i < j && nums.at(j) <= pivot) -- j; // scan from right to left
            if (i < j) nums.at(i ++) = nums.at(j); // place nums[j]
            
            while (i < j && nums.at(i) >= pivot) ++ i; // scan from left to right
            if (i < j) nums.at(j --) = nums.at(i); // place nums[i]
        }
        
        nums.at(i) = pivot; // place pivot key - the (i+1)-th largest key
        
        return i;
    }
    
    // priority_queue
    int findKthLargest3(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        
        for (int i = 0; i < k - 1; i ++)
            pq.pop(); // remove k-1 largest elements
        
        return pq.top(); // Kth largest element
    }

    // multiset
    int findKthLargest4(vector<int>& nums, int k) {
        multiset<int>   mset;
        
        for (int i = 0; i < nums.size(); ++ i) {
            mset.insert(nums.at(i));
            
            if (mset.size() > k)
                mset.erase(mset.begin()); // erase the element < Kth largest element
        }
        
        return *mset.begin(); // Kth largest element
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    vector<vector<int>>     aInputs = {{3,2,1,5,6,4}, {1,2,3,4,5}, {10,9,8,7,6}};
    vector<int>             kInputs = {2, 4, 2};
    int                     result;
    
    /*
     5
     2
     9
     */
    for (auto i = 0; i < aInputs.size(); ++ i) {
        result = testSolution.findKthLargest(aInputs[i], kInputs[i]);
        cout << result << endl;
        result = testSolution.findKthLargest2(aInputs[i], kInputs[i]);
        cout << result << endl;
        result = testSolution.findKthLargest3(aInputs[i], kInputs[i]);
        cout << result << endl;
        result = testSolution.findKthLargest4(aInputs[i], kInputs[i]);
        cout << result << endl;
    }
    
    return 0;
}
