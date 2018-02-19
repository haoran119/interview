//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sStack;
        
        for (char & ch : s) { // scan string with reference to save time
            switch (ch) {
                case '(':
                case '[':
                case '{': sStack.push(ch);
                          break;
                case ')': if (sStack.empty() || sStack.top() != '(') // pay attention to sStack.empty() for the case ')'
                              return false;
                          else {
                              sStack.pop();
                              break;
                          }
                case ']': if (sStack.empty() || sStack.top() != '[')
                              return false;
                          else {
                              sStack.pop();
                              break;
                          }
                case '}': if (sStack.empty() || sStack.top() != '{')
                              return false;
                          else {
                              sStack.pop();
                              break;
                          }
                default: ;
            }
        }
        
        return sStack.empty(); // check if all parentheses are matched
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    vector<string> iVec = {"()", "()[]{}", "(]", "([)]", "]"};
    bool result = true;

    result = result && testSolution.isValid(iVec[0]);
    result = result && testSolution.isValid(iVec[1]);
    result = result && ! testSolution.isValid(iVec[2]);
    result = result && ! testSolution.isValid(iVec[3]);
    result = result && ! testSolution.isValid(iVec[4]);

    if (result)
        cout << "All tests pass!" << endl;
    else
        cout << "Not all tests pass!" << endl;
    
    return 0;
}
