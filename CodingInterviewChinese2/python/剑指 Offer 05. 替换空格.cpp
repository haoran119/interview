//
//  LeetCode.cpp
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;


class Solution {
public:
    string replaceSpace(string s) {
        int len = s.size();

        if (len == 0)
            return "";

        int count = 0;
        for (char c : s)
            if (c == ' ')
                count ++;

        s.resize(len + count * 2);

        // Need two more char for each space
        int index_of_old = len - 1;
        int index_of_new = s.size() - 1;

        // In-place replacement
        while (index_of_old >= 0 and index_of_new > index_of_old) {
            if (s[index_of_old] == ' ') {
                s[index_of_new --] = '0';
                s[index_of_new --] = '2';
                s[index_of_new --] = '%';
            }
            else
                s[index_of_new --] = s[index_of_old];

            -- index_of_old;
        }

        return s;
    }
};


int main()
{
    string input = "We are happy.";

    Solution mySolution = Solution();
    string result = mySolution.replaceSpace(input);
    cout << result << endl;

    return 0;
}
