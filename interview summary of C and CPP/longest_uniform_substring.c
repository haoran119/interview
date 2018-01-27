//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct substr {
    int start, length;
} substr;

substr longest_uniform_substring(char * input)
{
    if (input == nullptr || strlen(input) == 0)
        return (substr){ -1, 0 };
    
    int st = 0, len = 1, resSt = 0, maxLen = 1, cur = 0;
    char cTemp = *input;

    ++ input;
    cur += 1;

    while (*input != '\0')  // pay attention to the terminator '\0'
    {
        if (*input == cTemp) {
            len += 1;
        } else {
            cTemp = *input;
            st = cur;
            len = 1;
        }
        
        if (len > maxLen) {
            resSt = st;
            maxLen = len;
        }
        
        ++ input;
        cur += 1;
    }
    
    return (substr){ resSt, maxLen };
}

int main(int argc, char* argv[])
{
    int result = 1;
    
    substr test = longest_uniform_substring("");
    result = result && (test.start == -1 && test.length == 0);

    test = longest_uniform_substring("10000111");
    result = result && (test.start == 1 && test.length == 4);

    test = longest_uniform_substring("aabbbbbCdAA");
    result = result && (test.start == 2 && test.length == 5);

    if (result)
        printf("ALl tests pass!\n");
    
    return 0;
}
