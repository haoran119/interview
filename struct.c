//
//  main.c
//  LeetCode
//
//  Created by Hao on 2017/11/22.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <stdio.h>

// Calculate the number of elements in x
#define myMacro(x) sizeof((x)) / sizeof((x[0]))

// Definition and initialization of array of struct
struct structTest {
    int   digit;
    char *number;
} strTest[] = { {1, "one"},     {2, "two"},
                {3, "three"},   {4, "four"},
                {5, "five"},    {6, "six"},
                {7, "seven"},   {8, "eight"},
                {9, "nine"},    {10, "ten"} };

int getNumber1(char *number)
{
    int i;
    
    printf("Before for-loop : i = %d\n\n", i);

    for (i = myMacro(strTest); i --;) // i -- will be executed at the BEGINNING of the first loop
    {
        printf("Loop i = %d\n", i);
        printf("[%d : %s]\n", strTest[i].digit, strTest[i].number);
        if (strcmp(strTest[i].number, number)) // return value 0 only if the contents of both strings are equal
        {
            printf("Before continue : %d\n", i);
            continue;
        }
        printf("Before break : %d\n", i);
        break;
    }
    
    printf("\nAfter for-loop : %d\n\n", i);
    return i;
}

int getNumber2(char *number)
{
    int i;
    
    printf("Before for-loop : i = %d\n\n", i);
    
    for (i = myMacro(strTest); ; i --) // i -- will be executed at the END of the first loop
    {
        printf("Loop i = %d\n", i);
        printf("[%d : %s]\n", strTest[i].digit, strTest[i].number);
        if (strcmp(strTest[i].number, number))
        {
            printf("Before continue : %d\n", i);
            continue;
        }
        printf("Before break : %d\n", i);
        break;
    }
    
    printf("\nAfter for-loop : %d\n\n", i);
    return i;
}

int main()
{
    printf("myMacro(strTest) = %d\n\n", myMacro(strTest));
    
    printf("getNumber1(\"zero\") = %d\n\n", getNumber1("zero"));

    printf("getNumber1(\"nine\") = %d\n\n", getNumber1("nine"));
    
    printf("getNumber2(\"zero\") = %d\n\n", getNumber2("zero"));
    
    printf("getNumber2(\"nine\") = %d\n\n", getNumber2("nine"));
    
    return 0;
}
