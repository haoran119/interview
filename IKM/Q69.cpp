//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
#include <unordered_map>

std::string checkTheLight() {
    return "green";
}

int main ()
{
    enum colors {green, yellow, red};
    
    /**1**/
    std::unordered_map<std::string, int> colorCommands = {{"red", 3}, {"yellow", 2}, {"green", 1}};
/*
    std::unordered_map<std::string, int> colorCommands;
    colorCommands["red"] = 3;
    colorCommands["yellow"] = 2;
    colorCommands["green"] = 1;

    std::unordered_map<std::string, int> colorCommands;
    colorCommands.insert(std::make_pair("red", 3));
    colorCommands.insert({ "yellow", 2 });
    colorCommands.emplace("green", 1);
*/
    std::string color = checkTheLight();

    /**2**/
//    switch (colorCommands.find(color)) // Statement requires expression of integer type ('iterator' (aka '__hash_map_iterator<__hash_iterator<std::__1::__hash_node<std::__1::__hash_value_type<std::__1::basic_string<char>, int>, void *> *> >') invalid)
    
    switch (colorCommands[color])
    {
    case green:
        std::cout << "get going";
        break;
    case yellow:
        std::cout << "slow down";
        break;
    case red:
    default:
        std::cout << "stop";
        break;
    }

    std::cout << std::endl;
    
    return 0;
}
