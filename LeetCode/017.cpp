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
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>  vResult;
        
        if (digits.empty()) return vResult;
        
        vector<string> dict{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        queue<string> myQueue;
        myQueue.push(""); // Tricky step for the initial value
        
        for (int i = 0; i < digits.size(); i ++) {
            int n = myQueue.size();
            string sTemp;
            
            for (int j = 0; j < n; j ++) {
                // retrieve old letter
                sTemp = myQueue.front();
                myQueue.pop();
                
                // append new letter
                for (auto & ch : dict[digits.at(i) - '0'])
                    myQueue.push(sTemp + ch);
            }
        }
        
        while (! myQueue.empty()) {
            vResult.push_back(myQueue.front());
            myQueue.pop();
        }
        
        return vResult;
    }
    
    vector<string> letterCombinations2(string digits) {
        vector<string> vResult;
        
        if (digits.empty()) return vResult;
        
        vector<string> dict{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vResult.push_back(""); // Tricky step for the initial value
        
        for (int i = 0; i < digits.size(); i ++) {
            vector<string> vTemp; // temp result to override the initial value ""
            string sTemp;
            
            for (int j = 0; j < vResult.size(); j ++) {
                sTemp = vResult[j];
                
                for (auto & ch : dict[digits.at(i) - '0'])
                    vTemp.push_back(sTemp + ch);
            }
            
            vResult.swap(vTemp); // update result iteratively
        }
        
        return vResult;
    }
};

int main(int argc, char* argv[])
{
    Solution    mySolution;
    
    vector<string>  inputs {"", "23"};
    vector<string>  outputs;
    
    /*
     
     ad ae af bd be bf cd ce cf
     */
    for (auto & input : inputs) {
        outputs = mySolution.letterCombinations(input);
        
        for (auto & output : outputs) {
            cout << output << " ";
        }
        cout << endl;

        outputs = mySolution.letterCombinations2(input);
        
        for (auto & output : outputs) {
            cout << output << " ";
        }
        cout << endl;
    }
    
    return 0;
}
