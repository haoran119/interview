//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Empty vector
        if (strs.empty()) return "";
        
        // Vertical scanning
        for (auto i = 0; i < strs[0].size(); i ++) {
            for (auto j = 1; j < strs.size(); j ++) {
                // Find the first string not matched
                // Do not use "i > strs[j].size() - 1" as it's of type size_t, 0 - 1 = INT_MAX rather than -1
                if (i == strs[j].size() || strs[j].at(i) != strs[0].at(i))
                    return strs[0].substr(0, i);
            }
        }
        
        return strs[0];
    }

};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    string      result;
    
    vector<vector<string>> sVec = {{"abab","aba",""}, {"test a short phrase", "test a slightly longer phrase"}};

    /*
     ""
     "test a s"
     */
    for (auto str : sVec) {
        result = testSolution.longestCommonPrefix(str);
        
        cout << result << endl;
    }

    return 0;
}
