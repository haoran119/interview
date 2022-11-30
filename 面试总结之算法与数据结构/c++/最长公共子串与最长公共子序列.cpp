//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

/*
http://www.cnblogs.com/pegasus923/p/7573973.html
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubstring(const string &str1, const string &str2) {
        vector< vector<int> > f(str1.size() + 1, vector<int>(str2.size() + 1) ); // 二维数组
        int result = 0;
        
        for (auto i = 0; i < str1.size() + 1; i ++) {
            for (auto j = 0; j < str2.size() + 1; j ++) {
                if (i == 0 || j == 0) // i == 0 or j == 0
                    f[i][j] = 0;
                else if (str1.at(i - 1) == str2.at(j - 1)) { // i, j > 0 and str1[i - 1] == str2[j - 1]
                    f[i][j] = f[i - 1][j - 1] + 1;
                    if (f[i][j] > result) result = f[i][j]; // 最长公共子串
                } else // i, j > 0 and str1[i - 1] != str2[j - 1], 区别于求最长公共子序列
                    f[i][j] = 0;
            }
        }
        
        return result;
    }

    int longestCommonSubsequence(const string &str1, const string &str2) {
        vector< vector<int> > f(str1.size() + 1, vector<int>(str2.size() + 1) ); // 二维数组
        int result = 0;
        
        for (auto i = 0; i < str1.size() + 1; i ++) {
            for (auto j = 0; j < str2.size() + 1; j ++) {
                if (i == 0 || j == 0) // i == 0 or j == 0
                    f[i][j] = 0;
                else if (str1.at(i - 1) == str2.at(j - 1)) { // i, j > 0 and str1[i - 1] == str2[j - 1]
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else // i, j > 0 and str1[i - 1] != str2[j - 1], 区别于求最长公共子串
                    f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            }
        }

        // 矩阵最后一个元素
        result = f[str1.size()][str2.size()];
        
        return result;
    }
};

int main ()
{
    Solution testSolution;
    
    vector<string> vecTest1{ {"ABCBDAB"}, {""}, {"ABC"}, {"ABC"} };
    vector<string> vecTest2{ {"BDCABA"}, {""}, {"DEF"}, {"ABC"} };
    
    for (auto i = 0; i < vecTest1.size(); i ++)
        cout << testSolution.longestCommonSubstring(vecTest1[i], vecTest2[i]) << endl;

    for (auto i = 0; i < vecTest1.size(); i ++)
        cout << testSolution.longestCommonSubsequence(vecTest1[i], vecTest2[i]) << endl;

    return 0;
}
