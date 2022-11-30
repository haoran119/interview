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
    string addBinary(string a, string b) {
        string result = "";
        const size_t size = a.size() > b.size() ? a.size() : b.size();
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int carry = 0;
        
        for (size_t i = 0; i < size; i ++) {
            const int ai = i < a.size() ? a[i] - '0' : 0;
            const int bi = i < b.size() ? b[i] - '0' : 0;
            const int val = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) / 2;
            result.insert(result.begin(), val + '0');
        }
        
        if (carry == 1)
            result.insert(result.begin(), '1');
        
        return result;
    }
};

int main ()
{
    Solution testSolution;
    string sTest[] = {"11", "1", "100", "11"};

    for (int i = 0; i < 2; i ++)
        cout << testSolution.addBinary(sTest[2 * i], sTest[2 * i + 1]) << endl;
    
    return 0;
}
