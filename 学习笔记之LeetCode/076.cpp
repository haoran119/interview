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
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        string sResult;
        unordered_map<char, int> hash;
        
        for (auto & ch : t)
            ++ hash[ch];
        
        // window start/end, sum{positive hash[i]}, min window size
        int left = 0, right = 0, count = t.size(), len = INT_MAX;
        
        while (right < s.size()) {
            if (hash[s.at(right)] > 0)
                -- count;
            
            -- hash[s.at(right)];
            
            ++ right;
            
            // found the valid window
            while (0 == count) {
                if (right - left < len) { // find the min window
                    len = right - left;
                    sResult = s.substr(left, len);
                }
                
                // move window left to minimize window, and restore hash value/count when kick out left point
                if (hash[s.at(left)] >= 0)
                    ++ count;
                
                ++ hash[s.at(left)];
                
                ++ left;
            }
        }
        
        if (len == INT_MAX)
            sResult = "";
        
        return sResult;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    vector<string>  sInputs = {"ADOBECODEBANC", "", "A", "ABC"};
    vector<string>  tInputs = {"ABC", "A", "", "DEF"};
    string          result;
    
    /*
     "BANC"
     ""
     ""
     ""
     */
    for (auto i = 0; i < sInputs.size(); ++ i) {
        result = testSolution.minWindow(sInputs[i], tInputs[i]);
        cout << "\"" << result << "\"" << endl;
    }
    
    return 0;
}
