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
    string countAndSay(int n) {
        if (n <= 0) return ""; // corner case
        
        string sResult = "1", sTemp = "";
        int count = 0, j = 0;
        
        for (int i = 1; i < n; i ++) {
            j = 0;
            sTemp = "";
            
            while (j < sResult.size()) {
                count = 1;
                
                while (j + 1 < sResult.size() && sResult.at(j) == sResult.at(j + 1)) {
                    ++ j;
                    ++ count;
                }
                
                sTemp = sTemp + to_string(count) + sResult.at(j);
                
                ++ j;
            }
            
            sResult = sTemp;
        }
        
        return sResult;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    string      result;
    
    vector<int> iVec = {0, 1, 2, 3, 4, 5};
    
    /*
     
     1
     11
     21
     1211
     111221
     */
    for (auto i : iVec) {
        cout << testSolution.countAndSay(i) << endl;
    }

    return 0;
}
