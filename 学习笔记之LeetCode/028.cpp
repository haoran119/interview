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
#include <cmath>
using namespace std;

class Solution {
public:
    // with string::find function
    int strStr(string haystack, string needle) {
        return (haystack.find(needle) != string::npos) ? haystack.find(needle) : -1;
    }
    
    // compare string
    int strStr1(string haystack, string needle) {
        // Corner case
        if (needle.empty()) return 0; // for both empty string should return 0
        if (haystack.empty()) return -1;
        
        bool flag;
        int n = haystack.size() - needle.size() + 1; // pay attention to + 1
        
        // better use < instead of <=
        for (int i = 0; i < n; i ++) {
            flag = true;
            
            for (int j = 0; j < needle.size(); j ++)
                if (haystack.at(i + j) != needle.at(j)) {
                    flag = false;
                    break;
                }
            
            if (flag)
                return i;
        }
        
        return -1;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    string      result;
    
    vector<vector<string>> sVec = {{"aaa","aaaa"}, {"", ""}, {"aaaaa", "bba"}, {"hello", "ll"}};
    
    /*
     -1
     -1
     0
     0
     -1
     -1
     2
     2
     */
    for (auto s : sVec) {
        cout << testSolution.strStr(s[0], s[1]) << endl;
        cout << testSolution.strStr1(s[0], s[1]) << endl;
    }

    return 0;
}
