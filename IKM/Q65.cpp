//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
using namespace std;

class animal {
    string name = "";
public:
    void setName(string n) { name = n; }
    string getName(void) { return name; }
};

void process(animal *pet)
{
    //I already have a pet
    unique_ptr<animal> myPet(new animal);   // Line A
    myPet->setName("Fluffy");

    // now you are getting a pet
    unique_ptr<animal> yourPet;

    // I'll give you my pet
    yourPet = move(myPet);                  // Line D

    // but you can't my pet's name
    myPet->setName ("Not Fluffy");          // Line B

    // I'll take the stray
    myPet.reset (pet);

    // the stray gets a new name
    myPet->setName("New Fluffy");
}

int main ()
{
    // in main...

    animal *stray = new animal;

    stray->setName("Scratchy");
    process (stray);
    string name = stray->getName();         // Line X

    // other code here
    
    return 0;
}
