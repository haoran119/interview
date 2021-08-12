//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // reverse
        reverse(matrix.begin(), matrix.end());
        
        // swap
        for (int i = 0; i < matrix.size(); i ++)
            for (int j = i + 1; j < matrix.size(); j ++)
                swap(matrix[i][j], matrix[j][i]);
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    vector<vector<vector<int>>>     inputs = {{{1,2,3},{4,5,6},{7,8,9}}, {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}};
    
    /*
     1 2 3
     4 5 6
     7 8 9
     
     ===>
     
     7 4 1
     8 5 2
     9 6 3
     
     5 1 9 11
     2 4 8 10
     13 3 6 7
     15 14 12 16
     
     ===>
     
     15 13 2 5
     14 3 4 1
     12 6 8 9
     16 7 10 11
     */
    for (auto & input : inputs) {
        for (auto & j : input) {
            for (auto & k : j)
                cout << k << " ";
            cout << endl;
        }
        
        cout << "\n===>\n" << endl;

        testSolution.rotate(input);

        for (auto & j : input) {
            for (auto & k : j)
                cout << k << " ";
            cout << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}
