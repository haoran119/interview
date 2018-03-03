//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
#include <future>
using namespace std;

int func1(std::future<int>& delayedParam)
{
    int x = delayedParam.get();     // Line A
    
    // do other work here...

    int y = function_potentially_throwing_exception();  // Line B

    return y;                       // Line C
}

void func2(std::promise<int> &result, std::promise<bool> &done)
{
    // do other work here...
    
    result.set_value(10);           // Line D
    done.set_value(true);           // Line E

    // could do other work here...
}

int main()
{
    //-----------------for func1----------------------------
    std::promise<int>   promisedArgument;
    std::future<int>    futureArgument = promisedArgument.get_future();

    auto f = std::async(std::launch::async, func1,
                        std::ref(futureArgument));  // Line F

    promisedArgument.set_value(4);                  // Line G

    try {
        bool isValid = f.valid();                   // Line H
        int yl = f.get();                           // Line I

        isValid = f.valid();                        // Line J
        int y2 = f.get();                           // Line K
    }
    catch (...) {
    //...
    }

    //--------------for func2--------------
    std::promise<int>       resultPromise;
    std::promise<bool>      donePromise;

    std::future<int>    resultFuture = resultPromise.get_future();
    std::future<bool>   doneFuture = donePromise.get_future();

    std::async(std::launch::async, func2,
               std::ref(resultPromise), std::ref(donePromise) );    // Line L

    bool done = doneFuture.get();           // Line M
    int result_f2 = resultFuture.get();     // Line N

    // do other things with result_f2 ...

    return 0;
}
