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
    // STL sort
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
    
    // Hash
    bool isAnagram2(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        vector<int> dict(26);
        
        for (auto ch : s) {
            ++ dict[ch - 'a'];
        }
        
        for (auto ch : t) {
            -- dict[ch - 'a'];
        }
        
        for (auto iter : dict) {
            if (iter != 0)
                return false;
        }
        
        return true;
    }
    
    bool isAnagram3(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        vector<int> dict(26);
        
        for (auto ch : s) {
            ++ dict[ch - 'a'];
        }
        
        for (auto ch : t) {
            -- dict[ch - 'a'];
            
            if (dict[ch - 'a'] < 0) // Extra characters in string t
                return false;
        }
        
        return true;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    int result = 1;
    
    result = result && testSolution.isAnagram("anagram", "nagaram");
    result = result && testSolution.isAnagram("program", "margorp");
    result = result && !testSolution.isAnagram("rat", "car");
    result = result && !testSolution.isAnagram("aaab", "aaa");
    result = result && testSolution.isAnagram("", "");
    
    result = result && testSolution.isAnagram2("anagram", "nagaram");
    result = result && testSolution.isAnagram2("program", "margorp");
    result = result && !testSolution.isAnagram2("rat", "car");
    result = result && !testSolution.isAnagram2("aaab", "aaa");
    result = result && testSolution.isAnagram2("", "");

    result = result && testSolution.isAnagram3("anagram", "nagaram");
    result = result && testSolution.isAnagram3("program", "margorp");
    result = result && !testSolution.isAnagram3("rat", "car");
    result = result && !testSolution.isAnagram3("aaab", "aaa");
    result = result && testSolution.isAnagram3("", "");

    if (result)
        cout << "ALl tests pass!" << endl;
    else
        cout << "Tests fail!" << endl;
    
    return 0;
}
