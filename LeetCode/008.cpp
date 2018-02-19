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
    int myAtoi(string str) {
        int i = 0;
        int result = 0;
        
        if (str.empty()) return 0;
        
        while (' ' == str.at(i) && i < str.size()) ++ i;
        
        if (i == str.size()) return 0;
        
        int sign = 1;
        
        if ('+' == str.at(i)) {
            sign = 1;
            ++ i;
        } else if ('-' == str.at(i)) {
            sign = -1;
            ++ i;
        }
        
        while (i < str.size() && isdigit(str.at(i))) {       // isdigit() from <cctype>
            if (result > (INT_MAX - (str.at(i) - '0')) / 10) // use > instead of >= for that abs(INT_MIN) (-2147483648) > abs(INT_MAX) (2147483647)
                return -1 == sign ? INT_MIN : INT_MAX;
            
            result = result * 10 + (str.at(i) - '0');
            
            ++ i;
        }
        
        return result * sign;
    }
    
    int myAtoi2(string str) {
        int num = 0;
        int sign = 1;
        int i = 0;
        const int n = str.length();
        
        if (n == 0) return 0;
        
        while ((str[i] == ' ') && (i < n))
            i ++;
        
        if (str[i] == '+')
            i ++;
        else if (str[i] == '-') {
            sign = -1;
            i ++;
        }
        
        while (i < n) {
            if (str[i] < '0' || str[i] > '9')
                break;
            
            // Be careful for out of range value
            if ((num > INT_MAX / 10) || ((num == INT_MAX / 10) && ((str[i] - '0') > INT_MAX % 10)))
                return sign == -1 ? INT_MIN : INT_MAX;
            
            num = num * 10 + (str[i] - '0');
            
            i ++;
        }
        
        return num * sign;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    string      result;
    
    vector<string> sVec = {"      -11919730356x", "", "1", "-2147483648", "-2147483647", "2147483647", "2147483648", "-3924x8fc", "+ 413", "++c", " ++1", "+413"};
    
    /*
     -2147483648
     0
     1
     -2147483648
     -2147483647
     2147483647
     2147483647
     -3924
     0
     0
     0
     413
     */
    for (auto s : sVec) {
        cout << testSolution.myAtoi(s) << endl;
        cout << testSolution.myAtoi2(s) << endl;
    }

    return 0;
}
