//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
    map<string, string> capitals;
    map<string, string>::iterator it;
    string west = "California";
    size_t numCities, numStates;

    capitals.insert(make_pair ("NewYork", "Albany"));   // misspelled
    capitals.insert(make_pair("Texas", "Houston"));     // wrong city
    capitals.insert(make_pair("California", "Sacramento"));

    for (auto &i : capitals) {
        cout << i.first << " " << i.second << endl;
    }
    
    cout << endl;

    numCities = capitals.count(west);
    
    cout << "numCities = " << numCities << endl;
    cout << endl;

    it = capitals.find("Houston");      // Alteration 1
    it->second = "Austin";              // Alteration 1

    for (auto &i : capitals) {
        cout << i.first << " " << i.second << endl;
    }

    cout << endl;
    
    it = capitals.find("NewYork");      // Alteration 2
    // No viable overloaded '='
//    it->first = "New York";             // Alteration 2

    string ILcap = capitals["Illinois"];
    numStates = capitals.size();
    
    for (auto &i : capitals) {
        cout << i.first << " " << i.second << endl;
    }

    cout << endl;

    cout << "ILcap = " << ILcap << endl;
    cout << "numStates = " << numStates << endl;

    return 0;
}
