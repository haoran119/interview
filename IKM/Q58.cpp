//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

template<class T>
void stripConst( T arg ) {
    typename std::remove_const<T>::type new_arg;
    
    if (std::is_const< decltype(new_arg) >::value)
        cout << "Type of new_arg is const" << endl;
    else
        cout << "Type of new_arg is not const" << endl;
}

int main(int argc, char **argv)
{
    stripConst( "Blinkin" );
    stripConst( 676 );
    stripConst( 3.14 );
    
    return 0;
}
