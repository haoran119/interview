//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
    enum    letterType {complement, complaint, unknown};
    
    string  letter = "happy sad happy sad sad";
    string  sHappy = "happy";
    string  sSad = "sad";
    
    pair<string, int>   happy = make_pair(sHappy, 0);
    pair<string, int>   sad = make_pair(sSad, 0);
    
    string  word;
    stringstream    ss(letter);
    vector<string>  letterWords;
    while (ss >> word) letterWords.push_back(word);
    
    vector<string>::iterator    words;
    for (words = letterWords.begin(); words < letterWords.end(); words ++) {
        word = *words;
        
        /*
         Following 2 lines is the answer
         */
        if (happy.first.find(word) != string::npos) happy.second ++;
        if (sad.first.find(word) != string::npos)   sad.second ++;
    }
    
    /*
     1
     */
    if (happy.second > sad.second)  return complement;
    else if (happy.second < sad.second) return complaint;
    else    return unknown;
}
