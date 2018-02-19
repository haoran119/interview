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
#include <unordered_map>    // unordered_map
#include <algorithm>        // sort
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>   group;
        
        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());   // Use the STL sort function to get the ordered string as key
            group[key].push_back(s);
        }
        
        vector<vector<string>>  result;
        
        for (auto iter : group) {
            result.push_back(iter.second);
        }
        
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    vector<string>  sample{"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>>  res;
    
    res = testSolution.groupAnagrams(sample);
    
    for (auto it : res) {
        for (auto str : it) {
            cout << str << endl;
        }
        cout << endl;
    }
    
    
    return 0;
}
