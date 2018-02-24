//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
using namespace std;

class SomeClass {
public:
    static int data;
};

/*
 The declaration of a static data member in the member list of a class is not a definition. You must define the static member outside of the class declaration, in namespace scope.
 */
int SomeClass::data = 0; // Definition or redeclaration of 'data' not allowed inside a function (including the main function)

SomeClass   objSome;

int main(int argc, char* argv[])
{
    /*
     0
     0
     */
    cout << SomeClass::data << endl;
    cout << objSome.data << endl;
    
//    cout << SomeClass<static int>.data << endl;
//    cout << objSome->data << endl;
//    cout << SomeClass::objSome.data << endl;
//    cout << objSome::data << endl;


    return 0;
}
