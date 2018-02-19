//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1)  return s;
        
        size_t start = 0, maxLen = 1;
        
        for (size_t i = 0; i < s.size(); ) {
            if (s.size() - i <= maxLen / 2) break;
            size_t j = i, k = i;
            
            // Duplicate characters
            while ((k < s.size() - 1) && (s[k] == s[k + 1])) k ++;
            
            // Move start pointer
            i = k + 1;
            
            // Expand
            while ((k < s.size() - 1) && (j > 0) && (s[k + 1] == s[j - 1])) {
                k ++;
                j --;
            }
            
            if (k - j + 1 > maxLen) {
                maxLen = k - j + 1;
                start = j;
            }
        }
        
        return s.substr(start, maxLen);
    }
};

int main ()
{
    Solution testSolution;
    string sTest[] = {"babad", "cbbd"};

    for (int i = 0; i < 2; i ++)
        cout << testSolution.longestPalindrome(sTest[i]) << endl;
    
    return 0;
}
