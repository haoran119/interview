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
    vector<int> partitionLabels(string S) {
        vector<int> vResult;
        
        // corner case
        if (S.empty()) return vResult;
        
        unordered_map<char, int> last;
        
        // the last occurred index of S[i]
        for (int i = 0; i < S.size(); ++ i)
            last[S.at(i)] = i;
        
        // start and end of the current window
        int left = 0, right = 0;
        
        // current pointer
        for (int i = 0; i < S.size(); ++ i) {
            right = max(right, last[S.at(i)]); // maximum index of the current window
            
            // reach the end of current window
            if (i == right) {
                vResult.push_back(right - left + 1); // size of the current window
                left = i + 1; // move to start of the next window
            }
        }
        
        return vResult;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    vector<string>  inputs = {"", "ababcbacadefegdehijhklij", "abcdefg", "aaaaaaaaaa"};
    vector<int>     result;
    
    /*
     
     9 7 8
     1 1 1 1 1 1 1
     10
     */
    for (auto input : inputs) {
        result = testSolution.partitionLabels(input);
        
        for (auto it : result)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}
