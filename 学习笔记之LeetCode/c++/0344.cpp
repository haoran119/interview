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
    // reverse
    string reverseString(string s) {
        string sr = s;
        
        reverse(sr.begin(), sr.end());
        
        return sr;
    }
    
    // swap
    string reverseString2(string s) {
        for (int i = 0; i < s.size() / 2; i ++)
            swap(s.at(i), s.at(s.size() - 1 - i));
        
        return s;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    vector<string> strs {"", "hello", "a.b,."};

    /*
     ""
     "olleh"
     ".,b.a"
     */
    for (auto s : strs) {
        cout << "\"" << testSolution.reverseString(s) << "\"" << endl;
        cout << "\"" << testSolution.reverseString2(s) << "\"" << endl;
    }
    
    return 0;
}
