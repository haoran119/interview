//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach #1 (Brute Force)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vResult;
        
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i + 1; j < nums.size(); j ++) { // j = i + 1 to avoid dup
                if (target == nums.at(i) + nums.at(j)) {
                    vResult.push_back(i);
                    vResult.push_back(j);
                }
            }
        }
        
        return vResult;
    }

    // Approach #2 (Two-pass Hash Table)
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> vResult;
        unordered_map<int, int> hashmap;
        
        for (int i = 0; i < nums.size(); i ++) {
            // hashmap.at(nums.at(i)) = i; // terminating with uncaught exception of type std::out_of_range: unordered_map::at: key not found
            hashmap[nums.at(i)] = i;
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            int complement = target - nums.at(i);
            
            if (hashmap.find(complement) != hashmap.end() && hashmap.at(complement) != i) {
                vResult.push_back(i);
                vResult.push_back(hashmap.at(complement));
                
                return vResult; // Need to return here, or else would find dup results (i, hashmap.at(complement)) & (hashmap.at(complement), i)
            }
        }
        
        return vResult;
    }

    // Approach #3 (One-pass Hash Table)
    vector<int> twoSum3(vector<int>& nums, int target) {
        vector<int> vResult;
        unordered_map<int, int> hashmap;
        
        for (int i = 0; i < nums.size(); i ++) {
            int complement = target - nums.at(i);
            
            if (hashmap.find(complement) != hashmap.end() && hashmap.at(complement) != i) {
                vResult.push_back(i);
                vResult.push_back(hashmap.at(complement));
            }
            
            hashmap[nums.at(i)] = i;
        }
        
        return vResult;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    string      result;
    
    vector<int> iVec = {2, 7, 11, 15};
    vector<int> vResult;

    /*
     0 1
     0 1
     1 0
     */
    vResult = testSolution.twoSum(iVec, 9);
    
    for (auto iter : vResult)
        cout << iter << " ";
    cout << endl;
    
    vResult.clear();
    
    vResult = testSolution.twoSum2(iVec, 9);
    
    for (auto iter : vResult)
        cout << iter << " ";
    cout << endl;

    vResult.clear();
    
    vResult = testSolution.twoSum3(iVec, 9);
    
    for (auto iter : vResult)
        cout << iter << " ";
    cout << endl;

    return 0;
}
