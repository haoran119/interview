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
    vector<int> findAnagrams(string s, string p) {
        vector<int> vResult;
        
        // corner case
        if (s.empty() || p.empty() || s.size() < p.size()) return vResult;
        
        unordered_map<char, int>    hash;
        
        // hash chars in p
        for (auto ch : p)
            ++ hash[ch];
        
        // two points indicating the begin/end of the window
        // count actually means the sum of all positive hash[i], and the sum of all hash[i] is always >= 0
        int left = 0, right = 0, count = p.size();
        
        while (right < s.size()) {
            // move window's right point rightward, if the char exists in p, decrease the count
            if (hash[s.at(right)] > 0)
                -- count;
            
            -- hash[s.at(right)];
            
            ++ right;
            
            // if the window's width == p.size(), then we have to slide window rightward for a new window, move the left point rightward
            if (right - left == p.size()) {
                // count == 0 if and only if every hash[i] == 0, means we find the anagram
                if (0 == count)
                    vResult.push_back(left);
                
                // Only increase the count if the char exists in p
                if (hash[s.at(left)] >= 0)
                    ++ count;
                
                ++ hash[s.at(left)];
                
                ++ left;
            }
        }
        
        return vResult;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    vector<string> iVec = {"cbaebabacd", "abc", "abab", "ab"};
    vector<int>     result;
    
    /*
     0 6
     0 1 2
     */
    for (int i = 0; i < iVec.size() - 1; i += 2) {
        result = testSolution.findAnagrams(iVec[i], iVec[i + 1]);
        
        for (auto it : result)
            cout << it << " ";
        cout << endl;
    }
    
    return 0;
}
