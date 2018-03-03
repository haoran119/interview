//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
using namespace std;

class widget {};

int main(int argc, char **argv)
{
    widget const *cw = new widget;
    widget *w;

/*
    w = cw; // Assigning to 'widget *' from incompatible type 'const widget *'
    w = reinterpret_cast< widget* >(cw); // Reinterpret_cast from 'const widget *' to 'widget *' casts away qualifiers
    w = static_cast< widget* >(cw); // Static_cast from 'const widget *' to 'widget *', which are not related by inheritance, is not allowed
*/
    w = const_cast< widget* >(cw);
    
    return 0;
}
