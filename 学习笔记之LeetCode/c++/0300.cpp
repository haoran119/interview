/*
https://leetcode.com/problems/longest-increasing-subsequence/

Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 
Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       if (nums.size() == 1) {
           return 1;
       }
       
       std::vector<int> v_LIS;
       
       for (const auto num : nums) {
           // find the first index "left" where LIS[left] >= num
           auto it = std::lower_bound(v_LIS.begin(), v_LIS.end(), num);
           
           // if num is greater than all LIS elements, append it
           if (it == v_LIS.end()) {
               v_LIS.emplace_back(num);
           }
           // if LIS[left-1] < num <= LIS[left], LIS[left] = num
           else {
               *it = num;
           }
       }

       return v_LIS.size();        
    }
};
