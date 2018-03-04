//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>

struct Gizmo {
    int pressure, rpm;
    Gizmo(int p, int r) : pressure(p), rpm(r) {}
//    Gizmo(const int p, const int r) : pressure(p), rpm(r) {}
};

struct Widget {
    int temp, speed;
    Widget() : temp (68), speed(100) {}
    
//    Widget(Widget& w);
    Widget(const Widget& w);
    
    Widget& operator=(Widget& rhs);
//    Widget& operator=(const Widget& rhs);

//    Widget(Gizmo& g);
    Widget(const Gizmo& g);
};

int main(int argc, char **argv)
{
    const Widget prototype;

    Widget basicWidget = prototype; // No matching constructor for initialization of 'Widget'

    Widget otherWidget;
    otherWidget = basicWidget;

    const Gizmo gadget(10, 100);

    Widget thirdWidget(gadget); // No matching constructor for initialization of 'Widget'

    return 1;
}
