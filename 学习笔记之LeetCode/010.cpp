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
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }

private:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        
        // next char is not '*', must match the current char
        if (*(p + 1) != '*') {
            if ((*p == *s) || ((*p == '.') && (*s != '\0')))
                return isMatch(s + 1, p + 1);
            else
                return false;
        } else { // next char is '*'
            // '*' matches zero or more of the preceding element
            while ((*p == *s) || ((*p == '.') && (*s != '\0'))) {
                // check if the remaining string matches
                if (isMatch(s, p + 2))
                    return true;
                // move point
                s ++;
            }
            // next matching
            return isMatch(s, p + 2);
        }
    }
};

int main ()
{
    Solution testSolution;
    string sTest[] = {"aa", "a", "aa", "aa", "aaa", "aa", "aa", "a*", "aa", ".*", "ab", ".*", "aab", "c*a*b"};

    for (int i = 0; i < 7; i ++)
        cout << testSolution.isMatch(sTest[2 * i], sTest[2 * i + 1]) << endl;
    
    return 0;
}
