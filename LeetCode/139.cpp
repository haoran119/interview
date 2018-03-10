//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
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
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>    f(s.size() + 1, false);
        
        /*
         F[i] stands for s[0...i-1] is a valid sequence
         F[0] = true;
         F[i] = F[j] && find(s[j...i-1])
         0 <= j < i
         0 <= i <= s.size()
         */
        f[0] = true;    // empty string

        for (int i = 1; i < s.size() + 1; i ++)
            for (int j = 0; j < i; j ++)
                if (f[j] && find( wordDict.begin(), wordDict.end(), s.substr( j, i - j ) ) != wordDict.end() ) {
                    f[i] = true;
                    break;
                }
        
        return f[s.size()];
    }
};

int main()
{
    Solution        testSolution;
    string          inputS = "leetcode";
    vector<string>  inputWD = {"leet","code"};
    
    /*
     1
     */
    cout << testSolution.wordBreak(inputS, inputWD) << endl;
    
    return 0;
}
