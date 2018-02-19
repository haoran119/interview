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
    // Only considering 26 ASCII characters
    int firstUniqChar(string s) {
        vector<int> dict(26, 0);
        
        for (auto& ch : s) {
            ++ dict[ch - 'a'];
        }
        
        for (int i = 0; i < s.size(); i ++) {
            if (dict[s.at(i) - 'a'] == 1)
                return i;
        }
        
        return -1;
    }

    // Common way for UNICODE characters
    int firstUniqChar2(string s) {
        unordered_map<char, int> dict; // character and index
        
        for (auto& ch : s) {
            ++ dict[ch];
        }
        
        for (int i = 0; i < s.size(); i ++) {
            if (dict[s.at(i)] == 1)
                return i;
        }
        
        return -1;
    }

    // Only traverse the string once
    int firstUniqChar3(string s) {
        unordered_map<char, int> dict;
        
        for (int i = 0; i < s.size(); i ++) {
            if (dict.end() == dict.find(s.at(i))) // pay attention to the condition check
                dict[s.at(i)] = i;
            else
                dict[s.at(i)] = INT_MAX; // for the dup
        }
        
        int res = INT_MAX;
        
        for (auto& it : dict) {
            res = min(res, it.second);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    vector<string> strs {"", "leetcode", "loveleetcode"};

    /*
     -1
     -1
     -1
     0
     0
     0
     2
     2
     2
     */
    for (auto s : strs) {
        cout << testSolution.firstUniqChar(s) << endl;
        cout << testSolution.firstUniqChar2(s) << endl;
        cout << testSolution.firstUniqChar3(s) << endl;
    }
    
    return 0;
}
