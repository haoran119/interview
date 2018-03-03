//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(int argc, char **argv)
{
    smatch matches;
    
    string  target("this subject has a submarine as a subsequence");
    regex  expr("\\b(sub)([^ ]*)");
    
    auto x = regex_search(target, matches, expr);  // Line 1

    return 0;
}
